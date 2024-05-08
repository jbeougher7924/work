#include <iostream>
#include "ecef_converter.h"
#include "geodetic_geocentric_converter.h"
#include "geodetic_ned_converter.h" // Include the header for GeodeticNEDConverter

int main()
{
    // Convert geodetic to ECEF
    Geodetic geodeticPoint = {37.7749, -122.4194, 0};
    ECEF ecefPoint = geodeticToECEF(geodeticPoint);

    std::cout << "Geodetic coordinates: (" << geodeticPoint.latitude << ", " << geodeticPoint.longitude << ", "
              << geodeticPoint.altitude << ")" << std::endl;
    std::cout << "ECEF coordinates: (" << ecefPoint.x << ", " << ecefPoint.y << ", " << ecefPoint.z << ")" << std::endl;

    // Convert ECEF back to geodetic
    Geodetic convertedGeodetic = ECEFToGeodetic(ecefPoint);

    std::cout << "Converted back to geodetic coordinates: (" << convertedGeodetic.latitude << ", "
              << convertedGeodetic.longitude << ", " << convertedGeodetic.altitude << ")" << std::endl;

    // Create an instance of the GeodeticGeocentricConverter
    GeodeticGeocentricConverter geoGeoConverter;

    // Define a geodetic coordinate (latitude, longitude, altitude)
    geodeticPoint = {37.7749, -122.4194, 0}; // San Francisco coordinates

    // Convert geodetic to geocentric
    Geocentric geocentricPoint = geoGeoConverter.geodeticToGeocentric(geodeticPoint);

    std::cout << "Geodetic coordinates: (" << geodeticPoint.latitude << ", " << geodeticPoint.longitude << ", "
              << geodeticPoint.altitude << ")" << std::endl;
    std::cout << "Geocentric coordinates: (" << geocentricPoint.x << ", " << geocentricPoint.y << ", " << geocentricPoint.z << ")" << std::endl;

    // Convert geocentric back to geodetic
    convertedGeodetic = geoGeoConverter.geocentricToGeodetic(geocentricPoint);

    std::cout << "Converted back to geodetic coordinates: (" << convertedGeodetic.latitude << ", "
              << convertedGeodetic.longitude << ", " << convertedGeodetic.altitude << ")" << std::endl;

    // Create an instance of the GeodeticNEDConverter
    GeodeticNEDConverter geoNedConverter;

    // Define a reference geodetic point
    Geodetic referencePoint = {37.7749, -122.4194, 0}; // San Francisco coordinates

    // Define a geodetic point for NED conversion
    Geodetic nedGeodeticPoint = {37.7750, -122.4195, 10}; // Slightly offset from reference point

    // Convert geodetic to NED relative to the reference point
    NED nedPoint = geoNedConverter.geodeticToNED(nedGeodeticPoint, referencePoint);

    std::cout << "Geodetic coordinates (NED reference): (" << referencePoint.latitude << ", " << referencePoint.longitude << ", " << referencePoint.altitude << ")" << std::endl;
    std::cout << "Geodetic coordinates (NED point): (" << nedGeodeticPoint.latitude << ", " << nedGeodeticPoint.longitude << ", " << nedGeodeticPoint.altitude << ")" << std::endl;
    std::cout << "NED coordinates: (" << nedPoint.north << ", " << nedPoint.east << ", " << nedPoint.down << ")" << std::endl;

    // Convert NED back to geodetic relative to the reference point
    Geodetic convertedNEDGeodetic = geoNedConverter.nedToGeodetic(nedPoint, referencePoint);

    std::cout << "Converted back to geodetic coordinates: (" << convertedNEDGeodetic.latitude << ", "
              << convertedNEDGeodetic.longitude << ", " << convertedNEDGeodetic.altitude << ")" << std::endl;

    return 0;
}
