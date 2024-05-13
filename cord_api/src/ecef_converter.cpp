#include "ecef_converter.h"

const double eccentricity = 0.0818191908426;
const double eccentricitySquared = eccentricity * eccentricity;
const double equatorialRadius = 6378137.0;

double degToRad(double degrees)
{
    return degrees * M_PI / 180.0;
}

double radToDeg(double radians)
{
    return radians * 180.0 / M_PI;
}

double getEarthRadius(double latitude)
{
    double sinLat = sin(latitude);
    return equatorialRadius / sqrt(1.0 - eccentricitySquared * sinLat * sinLat);
}

ECEF toECEF(const Geodetic &geodetic)
{
    double latitude = degToRad(geodetic.latitude);
    double longitude = degToRad(geodetic.longitude);
    double altitude = geodetic.altitude;

    double N = getEarthRadius(latitude);
    double x = (N + altitude) * cos(latitude) * cos(longitude);
    double y = (N + altitude) * cos(latitude) * sin(longitude);
    double z = (N * (1 - pow(eccentricity, 2)) + altitude) * sin(latitude);

    return {x, y, z};
}

Geodetic fromECEF(const ECEF &ecef)
{
    double x = ecef.x;
    double y = ecef.y;
    double z = ecef.z;

    double longitude = atan2(y, x);
    double p = sqrt(x * x + y * y);
    double latitude = atan2(z, p * (1 - eccentricitySquared));
    double N = getEarthRadius(latitude);
    double altitude = p / cos(latitude) - N;

    return {radToDeg(latitude), radToDeg(longitude), altitude};
}
