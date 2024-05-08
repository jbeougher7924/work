#ifndef GEODETIC_NED_CONVERTER_H
#define GEODETIC_NED_CONVERTER_H

#include "geodetic.h"

struct NED
{
    double north;
    double east;
    double down;
};

class GeodeticNEDConverter
{
public:
    GeodeticNEDConverter() {}

    NED geodeticToNED(const Geodetic &geodetic, const Geodetic &referencePoint) const;
    Geodetic nedToGeodetic(const NED &ned, const Geodetic &referencePoint) const;

private:
    double degToRad(double degrees) const;
    double radToDeg(double radians) const;
};

#endif /* GEODETIC_NED_CONVERTER_H */
