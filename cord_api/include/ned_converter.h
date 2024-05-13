#ifndef NED_CONVERTER_H
#define NED_CONVERTER_H

#include "geodetic.h"

struct NED
{
    double north;
    double east;
    double down;
};

class NEDConverter
{
public:
    NEDConverter() {}

    NED toNED(const Geodetic &geodetic, const Geodetic &referencePoint) const;
    Geodetic fromNED(const NED &ned, const Geodetic &referencePoint) const;

private:
    double degToRad(double degrees) const;
    double radToDeg(double radians) const;
};

#endif /* NED_CONVERTER_H */
