#ifndef NavigationWaypoints_h
#define NavigationWaypoints_h

#include <stdint.h>
#include <array>


enum eWaypointCategory
{
  BLUE_BUOY,
  NO_BUOY,
  PLATFORM,
  CONTAINER,
  ORANGE_BUOY,
  JETTY,
  UNMARKED
};

const char* featureCategoryToString(eWaypointCategory i);

class NavigationWaypoint
{
  public:
    const char* _label;
    const char* _m5label;
    const eWaypointCategory _cat;

    const double _lat;
    const double _long;

    NavigationWaypoint() : _label(nullptr), _m5label(nullptr), _cat(UNMARKED),_lat(0.0),_long(0.0) 
    {
    }

    NavigationWaypoint(const char*  label, const char* m5label, eWaypointCategory cat, double latitude, double longitude) : _label(label), _m5label(m5label), _cat(cat), _lat(latitude), _long(longitude)
    {
    }

    NavigationWaypoint(const char*  label, double latitude, double longitude) : _label(label), _m5label(label), _lat(latitude), _long(longitude), _cat(UNMARKED)
    {
    }
};

#define WAYPOINTS_COUNT 96

class WraysburyWaypoints
{
  public:
    static const std::array<NavigationWaypoint,WAYPOINTS_COUNT> waypoints;
    static const uint8_t getWaypointsCount() { return WAYPOINTS_COUNT; }
};

#endif

