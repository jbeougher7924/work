import geographiclib.geodesic as geodesic


# Constants for the WGS84 ellipsoid
a = geodesic.Constants.WGS84_a  # Semi-major axis in meters
f = geodesic.Constants.WGS84_f  # Flattening

# Create a geodesic object representing the WGS84 ellipsoid
earth = geodesic.Geodesic(a, f)




# Example geodetic coordinates (latitude, longitude, altitude)
latitude = 37.7749  # Example latitude in degrees
longitude = -122.419  # Example longitude in degrees
altitude = 0  # Example altitude in meters



# # Convert geodetic coordinates to geocentric coordinates
# x, y, z = earth.ToCartesian(latitude, longitude, altitude)


# Print the results
# print(f"Geodetic coordinates: ({latitude}, {longitude}, {altitude})")
# print(f"Geocentric coordinates: ({x}, {y}, {z})")
