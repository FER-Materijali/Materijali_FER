#include <stdio.h>
#include <math.h>
#define PI 3.14159f
#define R 6371

float stupnjeviURadijane(float stupnjevi)
{
	return (stupnjevi * 2 * PI) / 360;
}

float izracunajUdaljenost(float lat1, float lat2, float long1, float long2)
{
	float a;
	a = pow(sin((lat2 - lat1) / 2), 2) + cos(lat1) * cos(lat2) * pow(sin((long2 - long1) / 2), 2);
	return (R * 2 * atan2(sqrt(a), sqrt(1 - a)));
}



