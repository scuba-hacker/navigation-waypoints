#ifndef NavigationWaypoints_h
#define NavigationWaypoints_h

#include <stdint.h>
#include <array>

class NavigationWaypoint
{
  public:

    const char* _label;
    const char* _m5label;

    double _lat;
    double _long;

    NavigationWaypoint()
    {
      _label = nullptr;
      _lat = _long = 0.0;
    }

    NavigationWaypoint(const char*  label, const char* m5label, double latitude, double longitude) : _label(label), _m5label(m5label), _lat(latitude), _long(longitude)
    {
    }

    NavigationWaypoint(const char*  label, double latitude, double longitude) : _label(label), _m5label(label), _lat(latitude), _long(longitude)
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

