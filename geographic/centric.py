from pygeodesy import EcefKarney, Datums


earth = EcefKarney(Datums.WGS84)

# Example geodetic coordinates (latitude, longitude, altitude)
latitude = 37.7749  # Example latitude in degrees
longitude = -122.419  # Example longitude in degrees
altitude = 0  # Example altitude in meters



t = earth.forward(latitude, longitude, altitude)

# x, y, z = t[0:3]

# x, y, z = tuple(f'{x:.2e}' for x in t[:3])
print(tuple(f'{x:.5e}' for x in t[:3]))
# f'{number:e}'



x, y, z = t[0:3]
print (x, y, z)
k = earth.reverse(x, y, z)

print(k[3:6])
