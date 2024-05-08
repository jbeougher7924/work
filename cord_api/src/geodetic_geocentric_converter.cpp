#include "geodetic_geocentric_converter.h"

double GeodeticGeocentricConverter::degToRad(double degrees) const
{
    return degrees * M_PI / 180.0;
}

double GeodeticGeocentricConverter::radToDeg(double radians) const
{
    return radians * 180.0 / M_PI;
}

Geocentric GeodeticGeocentricConverter::geodeticToGeocentric(const Geodetic &geodetic) const
{
    double latitudeRad = degToRad(geodetic.latitude);
    double longitudeRad = degToRad(geodetic.longitude);
    double altitude = geodetic.altitude;

    double N = equatorialRadius / sqrt(1.0 - flattening * (2.0 - flattening) * pow(sin(latitudeRad), 2));
    double x = (N + altitude) * cos(latitudeRad) * cos(longitudeRad);
    double y = (N + altitude) * cos(latitudeRad) * sin(longitudeRad);
    double z = (N * (1.0 - flattening) + altitude) * sin(latitudeRad);

    return {x, y, z};
}

Geodetic GeodeticGeocentricConverter::geocentricToGeodetic(const Geocentric &geocentric) const
{
    double x = geocentric.x;
    double y = geocentric.y;
    double z = geocentric.z;

    double p = sqrt(x * x + y * y);
    double theta = atan2(z * equatorialRadius, p * (1.0 - flattening));
    double latitudeRad = atan2((z + flattening * equatorialRadius * pow(sin(theta), 3)), p - flattening * equatorialRadius * pow(cos(theta), 3));
    double longitudeRad = atan2(y, x);
    double N = equatorialRadius / sqrt(1.0 - flattening * pow(sin(latitudeRad), 2));
    double altitude = p / cos(latitudeRad) - N;

    return {radToDeg(latitudeRad), radToDeg(longitudeRad), altitude};
}
