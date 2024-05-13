#include <iostream>
#include "ecef_converter.h"
#include "geocentric_converter.h"

// Define a template function for converting ECEF to Geocentric
template <typename Func1, typename Func2>
auto geo_convert(Func1 fromECEFFunc, Func2 toGeocentricFunc) -> Geocentric
{
    // Call the first function (fromECEFFunc) and store its return value
    auto ecefPoint = fromECEFFunc();

    // Convert ECEF to Geocentric using the second function (toGeocentricFunc)
    auto geocentricPoint = toGeocentricFunc(ecefPoint);

    return geocentricPoint;
}

int main()
{
    // Example usage:
    ECEF ecefPoint = {37.7749, -122.4194, 0};

    // Call geo_convert with lambda functions for fromECEF and toGeocentric
    auto convertedGeocentric = geo_convert([&ecefPoint]()
                                           { return ecefPoint; }, [](const ECEF &ecef)
                                           {
        GeocentricConverter geoConverter;
        return geoConverter.toGeocentric(ecef); });

    // Print the converted Geocentric coordinates
    std::cout << "Geocentric coordinates: (" << convertedGeocentric.x << ", " << convertedGeocentric.y << ", " << convertedGeocentric.z << ")" << std::endl;

    return 0;
}
