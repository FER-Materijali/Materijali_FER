#define PI 3.14
#define R 6371
#include <math.h>

double stupnjeviuradijane(double kut) {
	return kut * ((2 * PI) / 360);
}

double izracunajudaljenost(double lat1, double lat2, double long1, double long2) {
	double a = pow(sin((lat2 - lat1) / 2), 2) + cos(lat1) * cos(lat2) * pow(sin((long2 - long1) / 2), 2);
	return R * 2 * atan2(sqrt(a), sqrt(1 - a));
}