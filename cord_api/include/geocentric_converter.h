#ifndef GEOCENTRIC_CONVERTER_H
#define GEOCENTRIC_CONVERTER_H

#include <cmath>
#include "geodetic.h"

// struct Geodetic
// {
//     double latitude;
//     double longitude;
//     double altitude;
// };

struct Geocentric
{
    double x;
    double y;
    double z;
};

class GeocentricConverter
{
public:
    GeocentricConverter() {}

    Geocentric toGeocentric(const Geodetic &geodetic) const;
    Geodetic fromGeocentric(const Geocentric &geocentric) const;

private:
    const double equatorialRadius = 6378137.0;     // Earth's equatorial radius in meters
    const double flattening = 1.0 / 298.257223563; // Earth's flattening

    double degToRad(double degrees) const;
    double radToDeg(double radians) const;
};

#endif /* GEOCENTRIC_CONVERTER_H */
