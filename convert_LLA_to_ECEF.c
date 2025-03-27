#include <stdio.h>
#include <math.h>

// Convert LLA to ECEF
void lla_to_ecef(double latitude, double longitude, double altitude, double *x, double *y, double *z)
{
    const double equatorial_radius = 6378137.0;           // Экваториальный радиус Земли в метрах
    const double eccentricity_squared = 0.00669437999014; // Квадрат эксцентриситета

    // Преобразование радианов в градусы
    double lat_rad = latitude * M_PI / 180.0;
    double lon_rad = longitude * M_PI / 180.0;

    double N = equatorial_radius / sqrt(1 - eccentricity_squared * pow(sin(lat_rad), 2));

    // Calculate ECEF coordinates
    *x = (N + altitude) * cos(lat_rad) * cos(lon_rad);
    *y = (N + altitude) * cos(lat_rad) * sin(lon_rad);
    *z = ((1 - eccentricity_squared) * N + altitude) * sin(lat_rad);
}

int main()
{
    double latitude, longitude, altitude;
    double x, y, z;

    // Get latitude
    printf("Enter latitude (-90 to 90 degrees): ");
    if (scanf("%lf", &latitude) != 1 || latitude < -90.0 || latitude > 90.0)
    {
        printf("Error: Invalid latitude input\n");
        return 1;
    }

    // Get longitude
    printf("Enter longitude (-180 to 180 degrees): ");
    if (scanf("%lf", &longitude) != 1 || longitude < -180.0 || longitude > 180.0)
    {
        printf("Error: Invalid longitude input\n");
        return 1;
    }

    // Get altitude
    printf("Enter altitude (in meters): ");
    if (scanf("%lf", &altitude) != 1)
    {
        printf("Error: Invalid altitude input\n");
        return 1;
    }

    lla_to_ecef(latitude, longitude, altitude, &x, &y, &z);

    // Print results with proper formatting
    printf("\nECEF Coordinates:\n");
    printf("X: %12.2f meters\n", x);
    printf("Y: %12.2f meters\n", y);
    printf("Z: %12.2f meters\n", z);

    return 0;
}