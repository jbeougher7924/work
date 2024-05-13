#include <iostream>
#include <GeographicLib/Geocentric.hpp>
#include <GeographicLib/LocalCartesian.hpp>

int main()
{
    GeographicLib::Geocentric earth(GeographicLib::Constants::WGS84_a(), GeographicLib::Constants::WGS84_f());

    double latitude = 37.7749;   // Example latitude in degrees
    double longitude = -122.419; // Example longitude in degrees
    double altitude = 0;         // Example altitude in meters

    double x, y, z;
    earth.Forward(latitude, longitude, altitude, x, y, z);

    std::cout << "Geodetic coordinates: (" << latitude << ", " << longitude << ", " << altitude << ")" << std::endl;
    std::cout << "Geocentric coordinates: (" << x << ", " << y << ", " << z << ")" << std::endl;

    earth.Reverse(x, y, z, latitude, longitude, altitude);

    std::cout << "Converted to Geodetic coordinates: (" << latitude << ", " << longitude << ", " << altitude << ")" << std::endl;

    // Create a LocalCartesian object for NED conversion
    GeographicLib::LocalCartesian proj(latitude, longitude, altitude);

    // Example North-East-Down (NED) offsets
    double north = 10.0; // Example NED offset in meters (North direction)
    double east = 5.0;   // Example NED offset in meters (East direction)
    double down = -2.0;  // Example NED offset in meters (Down direction)

    // Convert geodetic coordinates to NED coordinates
    double ned_latitude = 34.0549;
    double ned_longitude = -118.2426;
    double ned_altitude = 0;

    // proj.Forward(latitude, longitude, altitude, north, east, down);
    proj.Forward(ned_latitude, ned_longitude, ned_altitude, north, east, down);

    std::cout << "*******************************************************************************************************" << std::endl;

    std::cout << "Geodetic coordinates: (" << latitude << ", " << longitude << ", " << altitude << ")" << std::endl;
    std::cout << "NED coordinates: (" << north << ", " << east << ", " << down << ")" << std::endl;

    // Convert NED coordinates back to geodetic coordinates
    double back_latitude, back_longitude, back_altitude;
    proj.Reverse(north, east, down, back_latitude, back_longitude, back_altitude);

    std::cout << "Converted back to geodetic coordinates: (" << back_latitude << ", "
              << back_longitude << ", " << back_altitude << ")" << std::endl;

    return 0;
}
