#ifndef NavigationWaypoints_h
#define NavigationWaypoints_h

#include <stdint.h>
#include <array>

class NavigationWaypoint
{
  public:

    const char* _label;
    const char* _m5label;

    const double _lat;
    const double _long;

    NavigationWaypoint()
    {
      _label = nullptr;
      _lat = _long = 0.0;
    }

    NavigationWaypoint(const char*  label, const char* _m5label, double latitude, double longitude) : _label(label), _lat(latitude), _long(longitude)
    {
    }
};

#define WAYPOINTS_COUNT 96

class WraysburyWaypoints
{
  public:
    static const std::array<NavigationWaypoint,WAYPOINTS_COUNT> waypoints;
    static const uint8_t getWaypointsCount();
};

#endif
