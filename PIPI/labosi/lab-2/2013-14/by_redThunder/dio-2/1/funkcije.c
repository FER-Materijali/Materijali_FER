#include "funkcije.h"
#include <math.h>
#define PI 3.141593
#define R 6371

double stupnjeviURadijane ( double stup ){
	double rad;
	rad = stup / 180 * PI;
	return rad;
}

double izracunajUdaljenost ( double lat1, double lat2, double long1, double long2){
	double a,d;
	double rla1,rla2,rlo1,rlo2;
	rla1 = stupnjeviURadijane( lat1 );
	rla2 = stupnjeviURadijane( lat2 );
	rlo1 = stupnjeviURadijane( long1 );
	rlo2 = stupnjeviURadijane( long2 );

	a = pow( sin((rla2-rla1)/2), 2 ) + cos(rla1)*cos(rla2)*pow( sin((rlo2-rlo1)/2), 2 );
	d = R * 2 * atan2( sqrt(a), sqrt(1-a) );
	return d;
}