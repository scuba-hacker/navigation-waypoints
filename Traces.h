#ifndef TRACES_H
#define TRACES_H

#include <stdint.h>
#include <array>

struct trace_point
{
    double _la;
    double _lo;
};

#define HOLE_TRACE_COUNT 99
#define ALL_TRACE_COUNT 798
class WraysburyTraces
{
  public:
    static const std::array<trace_point,HOLE_TRACE_COUNT> hole_trace;
    static const std::array<trace_point,ALL_TRACE_COUNT> all_trace;
    static const int getHoleTraceCount() { return HOLE_TRACE_COUNT; }
    static const int getAllTraceCount() { return ALL_TRACE_COUNT; }
};

#endif
