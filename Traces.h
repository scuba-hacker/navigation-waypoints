#ifndef TRACES_H
#define TRACES_H

#include <stdint.h>
#include <array>

struct trace_point
{
    double _la;
    double _lo;
};

#define HOLE_TRACE_OLD_COUNT 99
#define ALL_TRACE_OLD_COUNT 798
#define ALL_TRACES_COUNT 1381
class WraysburyTraces
{
  public:
    static const std::array<trace_point,ALL_TRACE_OLD_COUNT> all_trace_old;
    static const int getAllTraceOldCount() { return ALL_TRACE_OLD_COUNT; }

    static const std::array<trace_point,ALL_TRACES_COUNT> all_trace;
    static const int getAllTraceCount() { return ALL_TRACES_COUNT; }


};

#endif
