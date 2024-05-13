#include <iostream>
#include "ecef_converter.h"
#include "geocentric_converter.h"
#include "ned_converter.h" // Include the header for GeodeticNEDConverter
#include "convert.h"

int main()
{
    // Convert geodetic to ECEF
    Geodetic geodeticPoint = {37.7749, -122.4194, 0};
    ECEF ecefPoint = toECEF(geodeticPoint);

    // std::cout << "Geodetic coordinates: (" << geodeticPoint.latitude << ", " << geodeticPoint.longitude << ", "
    //           << geodeticPoint.altitude << ")" << std::endl;
    std::cout << "ECEF coordinates: (" << ecefPoint.x << ", " << ecefPoint.y << ", " << ecefPoint.z << ")" << std::endl;

    // Convert ECEF back to geodetic
    Geodetic convertedGeodetic = fromECEF(ecefPoint);

    // std::cout << "Converted back to geodetic coordinates: (" << convertedGeodetic.latitude << ", "
    //           << convertedGeodetic.longitude << ", " << convertedGeodetic.altitude << ")" << std::endl;

    // Create an instance of the GeodeticGeocentricConverter
    GeocentricConverter geoGeoConverter;

    // Convert geodetic to geocentric
    Geocentric geocentricPoint = geoGeoConverter.toGeocentric(geodeticPoint);

    // geocentricPoint.x = -2706145.0987380478;
    // geocentricPoint.y = -4261078.381857123;
    // geocentricPoint.z = 3885725.490023605;

    // Convert geocentric back to geodetic
    convertedGeodetic = geoGeoConverter.fromGeocentric(geocentricPoint);

    std::cout << "Geodetic coordinates:                   (" << geodeticPoint.latitude << ", " << geodeticPoint.longitude << ", "
              << geodeticPoint.altitude << ")" << std::endl;

    std::cout << "Converted back to geodetic coordinates: (" << convertedGeodetic.latitude << ", "
              << convertedGeodetic.longitude << ", " << convertedGeodetic.altitude << ")" << std::endl;

    std::cout << "Geocentric coordinates: (" << geocentricPoint.x << ", " << geocentricPoint.y << ", " << geocentricPoint.z << ")" << std::endl;

    // Create an instance of the GeodeticNEDConverter
    NEDConverter geoNedConverter;

    // Define a reference geodetic point
    Geodetic referencePoint = {37.7749, -122.4194, 0}; // San Francisco coordinates

    // Define a geodetic point for NED conversion
    Geodetic nedGeodeticPoint = {37.7749, -122.4194, 0}; // Slightly offset from reference point

    // Convert geodetic to NED relative to the reference point
    NED nedPoint = geoNedConverter.toNED(nedGeodeticPoint, referencePoint);

    std::cout << "Geodetic coordinates (NED reference): (" << referencePoint.latitude << ", " << referencePoint.longitude << ", " << referencePoint.altitude << ")" << std::endl;
    std::cout << "Geodetic coordinates (NED point): (" << nedGeodeticPoint.latitude << ", " << nedGeodeticPoint.longitude << ", " << nedGeodeticPoint.altitude << ")" << std::endl;
    std::cout << "NED coordinates: (" << nedPoint.north << ", " << nedPoint.east << ", " << nedPoint.down << ")" << std::endl;

    // Convert NED back to geodetic relative to the reference point
    Geodetic convertedNEDGeodetic = geoNedConverter.fromNED(nedPoint, referencePoint);

    std::cout << "Converted back to geodetic coordinates: (" << convertedNEDGeodetic.latitude << ", "
              << convertedNEDGeodetic.longitude << ", " << convertedNEDGeodetic.altitude << ")" << std::endl;

    auto result = callFunctions([]()
                                { return add(10, 20); }, []()
                                { return multiply(3.5, 2.0); });

    std::cout << "Output: " << result << std::endl;

    // Create a lambda function that captures geodeticPoint by reference
    auto result2 = [&geodeticPoint]() -> ECEF
    {
        return toECEF(geodeticPoint);
    };

    // Call the conversion function with the lambda function
    auto convertedPoint = conversion(result2);

    std::cout << "ECEF coordinates: (" << convertedPoint.x << ", " << convertedPoint.y << ", " << convertedPoint.z << ")" << std::endl;

    return 0;
}
