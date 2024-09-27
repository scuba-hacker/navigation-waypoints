#ifndef TRACES_H
#define TRACES_H

#include <stdint.h>
#include <array>

struct trace_point
{
    double _la;
    double _lo;
};

#define BUS_TRACE_COUNT 99

class BusTrace
{
  public:
    static const std::array<trace_point,BUS_TRACE_COUNT> trace;
    static const uint8_t getBusTraceCount() { return BUS_TRACE_COUNT; }
};

#endif
