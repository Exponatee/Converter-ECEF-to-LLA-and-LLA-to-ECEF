#include <stdio.h>
#include <math.h>

// Convert ECEF to LLA (Latitude, Longitude, Altitude)
void ecef_to_lla(double x, double y, double z, double *latitude, double *longitude, double *altitude)
{
    const double equatorial_radius = 6378137.0;           // Earth's equatorial radius in meters (WGS84)
    const double eccentricity_squared = 0.00669437999014; // Squared eccentricity (WGS84)

    // Calculate longitude
    *longitude = atan2(y, x);
    double horizontal_distance = sqrt(x * x + y * y);
    double initial_latitude = atan2(z, horizontal_distance * (1 - eccentricity_squared));
    double prime_vertical_radius = equatorial_radius;

    for (int i = 0; i < 5; i++)
    {
        prime_vertical_radius = equatorial_radius / sqrt(1 - eccentricity_squared * pow(sin(initial_latitude), 2));
        initial_latitude = atan2(z + eccentricity_squared * prime_vertical_radius * sin(initial_latitude), horizontal_distance);
    }

    // Convert to degrees and calculate altitude
    *latitude = initial_latitude * 180.0 / M_PI;
    *longitude = *longitude * 180.0 / M_PI;
    *altitude = horizontal_distance / cos(initial_latitude) - prime_vertical_radius;
}

int main()
{
    double x, y, z;
    double latitude, longitude, altitude;

    // Get X coordinate
    printf("Enter X coordinate (in meters): ");
    if (scanf("%lf", &x) != 1)
    {
        printf("Error: Invalid X coordinate input\n");
        return 1;
    }

    // Get Y coordinate
    printf("Enter Y coordinate (in meters): ");
    if (scanf("%lf", &y) != 1)
    {
        printf("Error: Invalid Y coordinate input\n");
        return 1;
    }

    // Get Z coordinate
    printf("Enter Z coordinate (in meters): ");
    if (scanf("%lf", &z) != 1)
    {
        printf("Error: Invalid Z coordinate input\n");
        return 1;
    }

    // Perform conversion
    ecef_to_lla(x, y, z, &latitude, &longitude, &altitude);

    // Print results with proper formatting
    printf("\n\nGeodetic Coordinates:\n");
    printf("Latitude:  %12.6f degrees\n", latitude);
    printf("Longitude: %12.6f degrees\n", longitude);
    printf("Altitude:  %12.2f meters\n", altitude);

    return 0;
}