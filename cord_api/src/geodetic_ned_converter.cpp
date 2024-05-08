#include "geodetic_ned_converter.h"
#include <cmath>

double GeodeticNEDConverter::degToRad(double degrees) const
{
    return degrees * M_PI / 180.0;
}

double GeodeticNEDConverter::radToDeg(double radians) const
{
    return radians * 180.0 / M_PI;
}

NED GeodeticNEDConverter::geodeticToNED(const Geodetic &geodetic, const Geodetic &referencePoint) const
{
    double deltaLat = degToRad(geodetic.latitude - referencePoint.latitude);
    double deltaLon = degToRad(geodetic.longitude - referencePoint.longitude);
    double deltaAlt = geodetic.altitude - referencePoint.altitude;

    double sinLat = sin(degToRad(referencePoint.latitude));
    double cosLat = cos(degToRad(referencePoint.latitude));
    double sinLon = sin(degToRad(referencePoint.longitude));
    double cosLon = cos(degToRad(referencePoint.longitude));

    NED ned;
    ned.north = -sinLat * cosLon * deltaLat - sinLon * deltaLon + cosLat * cosLon * deltaAlt;
    ned.east = -sinLat * sinLon * deltaLat + cosLon * deltaLon + cosLat * sinLon * deltaAlt;
    ned.down = cosLat * deltaLat + sinLat * deltaAlt;

    return ned;
}

Geodetic GeodeticNEDConverter::nedToGeodetic(const NED &ned, const Geodetic &referencePoint) const
{
    double sinLat = sin(degToRad(referencePoint.latitude));
    double cosLat = cos(degToRad(referencePoint.latitude));
    double sinLon = sin(degToRad(referencePoint.longitude));
    double cosLon = cos(degToRad(referencePoint.longitude));

    Geodetic geodetic;
    geodetic.latitude = radToDeg(asin(-ned.north * sinLat - ned.east * cosLat));
    geodetic.longitude = radToDeg(atan2(-ned.east * sinLon, -ned.north * cosLat + ned.east * sinLat * cosLon)) + referencePoint.longitude;
    geodetic.altitude = referencePoint.altitude - ned.down;

    return geodetic;
}
