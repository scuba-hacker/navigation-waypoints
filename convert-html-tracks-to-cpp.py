#!/usr/bin/env python3
"""
Parse a JS file containing multiple tracks and emit C++ std::array<trace_point, N>
per track, plus an all_traces concatenation array.

- Array name comes from trk[t].info.name (sanitised to a valid C++ identifier).
- Collects ALL segments.push({points:[ ... ]}) for the current t and concatenates them per track.
- Ignores the 3rd value (alt) in each triple.
- Emits std::array for each track and for all_traces.
"""

from __future__ import annotations

import re
import sys
from dataclasses import dataclass, field
from pathlib import Path
from typing import Dict, List, Tuple


# --- Regexes ---
RE_T_ASSIGN = re.compile(r"\bt\s*=\s*(\d+)\s*;")
RE_TRACK_NAME = re.compile(r"trk\s*\[\s*t\s*]\s*\.\s*info\s*\.\s*name\s*=\s*(['\"])(.*?)\1\s*;")
RE_SEGMENT_PUSH = re.compile(
    r"trk\s*\[\s*t\s*]\s*\.\s*segments\s*\.\s*push\s*\(\s*\{\s*points\s*:\s*\[(.*?)\]\s*\}\s*\)\s*;",
    flags=re.DOTALL,
)
RE_TRIPLE = re.compile(
    r"\[\s*([+-]?\d+(?:\.\d+)?)\s*,\s*([+-]?\d+(?:\.\d+)?)\s*,\s*([+-]?\d+(?:\.\d+)?)\s*\]"
)
RE_WS = re.compile(r"\s+")


@dataclass
class Track:
    t: int
    name: str | None = None
    points: List[Tuple[float, float]] = field(default_factory=list)


def sanitize_cpp_identifier(name: str) -> str:
    """
    Convert arbitrary track name into a valid C++ identifier:
      - whitespace => '_'
      - non [A-Za-z0-9_] => '_'
      - collapse multiple underscores
      - if starts with digit => prefix '_'
      - avoid empty
    """
    s = RE_WS.sub("_", name.strip())
    s = re.sub(r"[^A-Za-z0-9_]", "_", s)
    s = re.sub(r"_+", "_", s).strip("_")
    if not s:
        s = "Track"
    if s[0].isdigit():
        s = "_" + s
    return s


def parse_js_tracks(text: str) -> Dict[int, Track]:
    tracks: Dict[int, Track] = {}
    current_t: int | None = None

    # Scan tokens in source order so "current t" is well-defined.
    token_re = re.compile(
        r"(?P<tassign>\bt\s*=\s*\d+\s*;)"
        r"|(?P<name>trk\s*\[\s*t\s*]\s*\.\s*info\s*\.\s*name\s*=\s*(['\"]).*?\3\s*;)"
        r"|(?P<push>trk\s*\[\s*t\s*]\s*\.\s*segments\s*\.\s*push\s*\(\s*\{\s*points\s*:\s*\[.*?\]\s*\}\s*\)\s*;)",
        flags=re.DOTALL,
    )

    for m in token_re.finditer(text):
        tok = m.group(0)

        mt = RE_T_ASSIGN.search(tok)
        if mt:
            current_t = int(mt.group(1))
            tracks.setdefault(current_t, Track(t=current_t))
            continue

        mn = RE_TRACK_NAME.search(tok)
        if mn:
            if current_t is None:
                continue
            tracks.setdefault(current_t, Track(t=current_t))
            tracks[current_t].name = mn.group(2)
            continue

        mp = RE_SEGMENT_PUSH.search(tok)
        if mp:
            if current_t is None:
                continue
            tracks.setdefault(current_t, Track(t=current_t))
            payload = mp.group(1)
            for la, lo, _alt in RE_TRIPLE.findall(payload):
                tracks[current_t].points.append((float(la), float(lo)))
            continue

    return tracks


def render_cpp(tracks: Dict[int, Track]) -> str:
    # Deterministic order by track number; skip empty tracks
    ordered = [tracks[k] for k in sorted(tracks.keys()) if tracks[k].points]

    # Resolve array names and de-duplicate
    used: Dict[str, int] = {}
    arrays: List[Tuple[str, Track]] = []
    for tr in ordered:
        base = sanitize_cpp_identifier(tr.name) if tr.name else f"Track_{tr.t}"
        used[base] = used.get(base, 0) + 1
        name = base if used[base] == 1 else f"{base}_{used[base]}"
        arrays.append((name, tr))

    out: List[str] = []
    out.append("#include <array>")
    out.append("#include <cstddef>")
    out.append("")
    out.append("struct trace_point")
    out.append("{")
    out.append("    double _la;")
    out.append("    double _lo;")
    out.append("};")
    out.append("")

    # Emit per-track std::array
    for name, tr in arrays:
        n = len(tr.points)
        out.append(f"// Track #{tr.t}" + (f": {tr.name}" if tr.name else ""))
        out.append(f"static constexpr std::array<trace_point, {n}> {name}{{{{")
        for la, lo in tr.points:
            out.append(f"    {{ {la:.15g}, {lo:.15g} }},")
        out.append("}};")
        out.append("")

    # Emit concatenated std::array all_traces
    if arrays:
        all_points: List[Tuple[float, float]] = []
        for _name, tr in arrays:
            all_points.extend(tr.points)

        out.append("// Concatenation of all tracks (in track-number order)")
        out.append(f"static constexpr std::array<trace_point, {len(all_points)}> all_traces{{{{")
        # Keep the helpful comment boundaries
        for name, tr in arrays:
            out.append(f"    // {name}")
            for la, lo in tr.points:
                out.append(f"    {{ {la:.15g}, {lo:.15g} }},")
        out.append("}}};")
        out.append("")
    else:
        out.append("// No tracks with points found.")

    return "\n".join(out)


def main() -> int:
    if len(sys.argv) < 2:
        print("Usage: js_tracks_to_cpp.py <input.js> [output.cpp]", file=sys.stderr)
        return 2

    infile = Path(sys.argv[1])
    text = infile.read_text(encoding="utf-8", errors="replace")

    tracks = parse_js_tracks(text)
    cpp = render_cpp(tracks)

    if len(sys.argv) >= 3:
        Path(sys.argv[2]).write_text(cpp, encoding="utf-8")
    else:
        sys.stdout.write(cpp)

    return 0


if __name__ == "__main__":
    raise SystemExit(main())

