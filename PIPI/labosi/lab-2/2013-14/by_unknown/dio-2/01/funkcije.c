#include"funkcije.h"
#include<math.h>
#define PI 3.14159265358979323846
#define R 6371

double stupnjeviURadijane(double deg){
									double rad=0;
									rad=PI*(deg/180);
									return rad;
}

double izracunajUdaljenost(double lat1, double lat2, double long1, double long2){
																				double a=0, d=0, lt1=0, lt2=0, lg1=0, lg2=0;
																				lt1=stupnjeviURadijane(lat1);
																				lt2=stupnjeviURadijane(lat2);
																				lg1=stupnjeviURadijane(long1);
																				lg2=stupnjeviURadijane(long2);
																				a=pow(sin((lt2-lt1)/2),2) + cos(lt1)*cos(lt2)*pow(sin((lg2-lg1)/2),2);
																				d=2*R*atan2(sqrt(a),sqrt(1-a));
																				return d;
}
																				
																				
