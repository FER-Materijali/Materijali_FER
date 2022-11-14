#include <math.h>
#define R 6371
#define PI 3.141592653589793

double stupnjeviURadijane(double kut) {
	return (kut*(PI/180));
}

double izracunajUdaljenost(double lat1, double long1, double lat2, double long2) {
	double a;
	double distance;
	a = pow(sin((lat2-lat1)/2), 2) + cos(lat1) * cos(lat2) * pow(sin((long2-long1)/2), 2);
	distance = R * 2 * atan2(sqrt(a),sqrt(1 - a));
	return distance;
}