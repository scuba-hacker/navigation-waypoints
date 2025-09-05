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
  UNMARKED,
  UNKNOWN
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

// including wraysbury, home, vobster and dover
#define WAYPOINTS_COUNT 91
class WraysburyWaypoints
{
  public:
    static const std::array<NavigationWaypoint,WAYPOINTS_COUNT> waypoints;
    static const uint8_t getWaypointsCount() { return WAYPOINTS_COUNT; }
    static const uint8_t getStartIndexWraysbury() { return 0;}
    static const uint8_t getEndWaypointIndexWraysbury() { return 86;}
    static const uint8_t getStartIndexHome() { return 86;}
    static const uint8_t getEndWaypointIndexHome() { return 88;}
    static const uint8_t getStartIndexVobster() { return 88;}
    static const uint8_t getEndWaypointIndexVobster() { return 90;}
    static const uint8_t getStartIndexOtherAreas() { return 90;}
    static const uint8_t getEndWaypointIndexOtherAreas() { return 91;}
};

#endif

