#include<math.h>
#include"funkcije.h"
#define R 6371
#define PI 3.141593
double stupnjeviURadijane (double kutstup) {
    double kutrad;
	kutrad=(kutstup/180)*PI;
	return kutrad;
}
double izracunajUdaljenost (double lat1d, double lat2d, double long1d, double long2d) {
	double a, d, lat1, lat2, long1, long2;
	lat1=stupnjeviURadijane(lat1d);
	lat2=stupnjeviURadijane(lat2d);
	long1=stupnjeviURadijane(long1d);
	long2=stupnjeviURadijane(long2d);
	a=pow(sin((lat2-lat1)/2),2)+cos(lat1)*cos(lat2)*pow(sin((long2-long1)/2),2);
	d=R*2*atan2(sqrt(a), sqrt(1-a));
	return d;
}