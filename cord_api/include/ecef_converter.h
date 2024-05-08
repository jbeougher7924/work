#ifndef ECEF_CONVERTER_H
#define ECEF_CONVERTER_H

#include <cmath>
#include "geodetic.h"

struct ECEF
{
    double x;
    double y;
    double z;
};

// struct Geodetic
// {
//     double latitude;
//     double longitude;
//     double altitude;
// };

double degToRad(double degrees);
double radToDeg(double radians);
double getEarthRadius(double latitude);
ECEF geodeticToECEF(const Geodetic &geodetic);
Geodetic ECEFToGeodetic(const ECEF &ecef);

#endif /* ECEF_CONVERTER_H */
