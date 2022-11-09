#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

string randomStrGen(int length) {
    static string charset = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string result;
    result.resize(length);
    
    for (int i = 0; i < length; i++)
        result[i] = charset[rand() % charset.length()];

    return result;
}

int main(int argc, char **argv) {
	int n;
	
	srand(time(NULL));
	
	if(argc >= 2) {
		sscanf(argv[1], "%d", &n);
	}
	else cin >> n;
	
	for(int i = 0; i < n; ++i) {
		double omjer = (double)rand() / RAND_MAX;
		unsigned long long int q = 1000000000000 + 8999999999999 * omjer; 
		cout << q << " " << randomStrGen(8) << endl;
	}
	return 0;
}
