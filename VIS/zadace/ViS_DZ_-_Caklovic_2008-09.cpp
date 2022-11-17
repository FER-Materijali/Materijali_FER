#include <iostream>
#include <cmath>



using namespace std;
       

void u_test(double alfa, double x_srednji, int a0, int n, double sigma_da, char alternativa){
     double p, p1, u, sigma;  int i, e=0;
     double normalna[37][2]= {
       {0.55, 0.12566}, {0.60,0.25335}, {0.65,0.38532}, {0.70, 0.52440}, {0.75, 0.67449},
       {0.80, 0.84162}, {0.82, 0.91537}, {0.84, 0.99446}, {0.86, 1.08032}, {0.88, 1.17499},
       {0.90, 1.28155}, {0.91, 1.34076}, {0.92, 1.040507}, {0.93, 1.17579}, {0.94, 1.55477},
       {0.95, 1.64485}, {0.96, 1.75069}, {0.97, 1.88079}, {0.975, 1.95996}, {0.98, 2.05375},
       {0.99, 2.32635}, {0.991, 2.36562}, {0.992, 2.40892}, {0.993, 2.45726}, {0.994, 2.51214},
       {0.995, 2.57583}, {0.996, 2.65207}, {0.997, 2.74778}, {0.9975, 2.80703}, {0.998, 2.87816},
       {0.999, 3.09023}, {0.9995, 3.29053}, {0.9999, 3.71901}, {0.99995, 3.89059}, {0.99999, 4.26489},
       {0.999999, 4.75342}
       };
     
     p=1-alfa;
     p1=1-(alfa/2);
     
     sigma=sqrt(sigma_da);
     
     u=((x_srednji - a0)/sigma)*sqrt(n);
     
     cout << "\n Vrijednost statistike uzorka je:  " << u << endl;
     
     if (alternativa!='z') {
        for (i=0;i<36;i++){
         if (p==normalna[i][0]) e=i;
         }
         cout << "\n kvantil normalne razdiobe iz tablice je   " << normalna[e][1] << endl;
          if (abs(u)> normalna[e][1]) {
          cout << "\n Hipoteza se odbacuje. " << endl;
          }
          else cout << "\n Hipoteza se ne moze odbaciti. " << endl;
               }
          
        
     else {
          for (i=0;i<36;i++){
          if (p1==normalna[i][0]){ e=i;
         }
         }
         cout << "\n kvantil normalne razdiobe iz tablice je   " << normalna[e][1] << endl;
          if (abs(u)> normalna[i][1]) cout << "\n Hipoteza se odbacuje. " << endl;
          else cout << "\n Hipoteza se ne moze odbaciti. " << endl;
          }
     
     
};

void t_test(int n, double x_srednji, int a, double alfa, double podaci[]){
     int i,j,k,c=0,e;
     double s=0, t_stud=0, t, b, temp = 0;
     double student[40][15]={
     {0, 0.50, 0.40, 0.30, 0.20, 0.10, 0.05, 0.02, 0.01, 0.005, 0.002, 0.001},
     {1, 1, 1.376, 1.963, 3.078, 6.314, 12.71, 31.82, 63.66, 127.3, 318.3, 636.6},
     {2, 0.816, 1.061, 1.386, 1.886, 2.92, 4.303, 6.965, 9.925, 14.09, 22.33, 31.6},
     {3, 0.765, 0.978, 1.25, 1.638, 2.353, 3.182, 4.541, 5.841, 7.453, 10.21, 12.92},
     {4, 0.741, 0.941, 1.19, 1.533, 2.132, 2.776, 3.747, 4.604, 5.598, 7.173, 8.61},
     {5, 0.727, 0.92, 1.156, 1.476, 2.015, 2.571, 3.365, 4.032, 4.773, 5.893, 6.869},
     {6, 0.718, 0.906, 1.134, 1.44, 1.943, 2.447, 3.143, 3.707, 4.317, 5.208, 5.959},
     {7, 0.711, 0.896, 1.119, 1.415, 1.895, 2.365, 2.998, 3.499, 4.029, 4.785, 5.408},
     {8, 0.706, 0.889, 1.108, 1.397, 1.86, 2.306, 2.896, 3.355, 3.833, 4.501, 5.041},
     {9, 0.703, 0.883, 1.1, 1.383, 1.833, 2.262, 2.821, 3.25, 3.69, 4.297, 4.781},
     {10, 0.7, 0.879, 1.093, 1.372, 1.812, 2.228, 2.764, 3.169, 3.581, 4.144, 4.587},
     {11, 0.697, 0.876, 1.088, 1.363, 1.796, 2.201, 2.718, 3.106, 3.497, 4.025, 4.437},
     {12, 0.695, 0.873, 1.083, 1.356, 1.782, 2.179, 2.681, 3.055, 3.428, 3.93, 4.318},
     {13, 0.694, 0.87, 1.079, 1.35, 1.771, 2.16, 2.65, 3.012, 3.372, 3.852, 4.221},
     {14, 0.692, 0.868, 1.076, 1.345, 1.761, 2.145, 2.624, 2.977, 3.326, 3.787, 4.14},
     {15, 0.691, 0.866, 1.074, 1.341, 1.753, 2.131, 2.602, 2.947, 3.286, 3.733, 4.073},
     {16, 0.69, 0.865, 1.071, 1.337, 1.746, 2.12, 2.583, 2.921, 3.252, 3.686, 4.015},
     {17, 0.689, 0.863, 1.069, 1.333, 1.74, 2.11, 2.567, 2.898, 3.222, 3.646, 3.965},
     {18, 0.688, 0.862, 1.067, 1.33, 1.734, 2.101, 2.552, 2.878, 3.197, 3.61, 3.922},
     {19, 0.688, 0.861, 1.066, 1.328, 1.729, 2.093, 2.539, 2.861, 3.174, 3.579, 3.883},
     {20, 0.687, 0.86, 1.064, 1.325, 1.725, 2.086, 2.528, 2.845, 3.153, 3.552, 3.85},
     {21, 0.686, 0.859, 1.063, 1.323, 1.721, 2.08, 2.518, 2.831, 3.135, 3.527, 3.819},
     {22, 0.686, 0.858, 1.061, 1.321, 1.717, 2.074, 2.508, 2.819, 3.119, 3.505, 3.792},
     {23, 0.685, 0.858, 1.06, 1.319, 1.714, 2.069, 2.5, 2.807, 3.104, 3.485, 3.767},
     {24, 0.685, 0.857, 1.059, 1.318, 1.711, 2.064, 2.492, 2.797, 3.091, 3.467, 3.745},
     {25, 0.684, 0.856, 1.058, 1.316, 1.708, 2.06, 2.485, 2.787, 3.078, 3.45, 3.725},
     {26, 0.684, 0.856, 1.058, 1.315, 1.706, 2.056, 2.479, 2.779, 3.067, 3.435, 3.707},
     {27, 0.684, 0.855, 1.057, 1.314, 1.703, 2.052, 2.473, 2.771, 3.057, 3.421, 3.69},
     {28, 0.683, 0.855, 1.056, 1.313, 1.701, 2.048, 2.467, 2.763, 3.047, 3.408, 3.674},
     {29, 0.683, 0.854, 1.055, 1.311, 1.699, 2.045, 2.462, 2.756, 3.038, 3.396, 3.659},
     {30, 0.683, 0.854, 1.055, 1.31, 1.697, 2.042, 2.457, 2.75, 3.03, 3.385, 3.646},
     {40, 0.681, 0.851, 1.05, 1.303, 1.684, 2.021, 2.423, 2.704, 2.971, 3.307, 3.551},
     {50, 0.679, 0.849, 1.047, 1.299, 1.676, 2.009, 2.403, 2.678, 2.937, 3.261, 3.496},
     {60, 0.679, 0.848, 1.045, 1.296, 1.671, 2, 2.39, 2.66, 2.915, 3.232, 3.46},
     {80, 0.678, 0.846, 1.043, 1.292, 1.664, 1.99, 2.374, 2.639, 2.887, 3.195, 3.416},
     {100, 0.677, 0.845, 1.042, 1.29, 1.66, 1.984, 2.364, 2.626, 2.871, 3.174, 3.39},
     {120, 0.677, 0.845, 1.041, 1.289, 1.658, 1.98, 2.358, 2.617, 2.86, 3.16, 3.373},
     {1e+06, 0.674, 0.842, 1.036, 1.282, 1.645, 1.96, 2.326, 2.576, 2.807, 3.09, 3.291}
     };  
     
     cout << x_srednji<< endl;
     for (i=0; i<n; i++)
         temp = temp + (podaci[i] - x_srednji)*(podaci[i] - x_srednji);
         cout << temp << endl;
     
     s=sqrt(temp/(n-1));
     
     cout << "\n Disperzija uzorka iznosi : s(kapa)=" << s << endl;
     t=((x_srednji - a)/s)*sqrt(n);
     
     cout << "\n Vrijednost statistike uzorka je:  " << t << endl;
     cout << "\n Stupanj slobode je " << n-1 << endl;
     b=2*alfa;
     
     
     for (j=0;j<12;j++){ 
         if (b == student[0][j]) c=j;
     }
     
     for (k=0;k<40;k++){
         if ((n-1)== student[k][0])e=i;
           }
           
     t_stud=0-student[e][c];
           
     cout << "\n kvantil studentove razdiobe iz tablice je   " << t_stud << endl;
     if (t<t_stud) cout << "\n Hipoteza se odbacuje. " << endl;
           else cout << "\n Hipoteza se ne moze odbaciti. " << endl;
            
};

int main() {
    int  a;  char alternativa, p_ili_s;

    cout<<"\n "<< endl;
    cout<<"\n "<< endl;
    cout<<"\n Program koji vrsi provjeru istinitosti neke, od korisnika zadane hipoteze"<< endl;
    
    cout<<"\n  Student: Maja Fistric'    JMBAG: 0036430830      Grupa: 2.R3       Rbr: 18  \n\n"<< endl;
 

    cout<<"\n Unesite  parametar a koji odgovara Vasoj temeljnoj hipotezi H0    a= ";
    cin >> a;
    cout<<"\n ";
    
    cout << "\n Odaberite alternativnu hipotezu H1 \n        za a>a0 odaberite x \n        za  a<a0 odaberite y \n        za  a!=a0 odaberite z \n \n  Izabrali ste: ";
    cin >> alternativa;
    cout << "\n";
    
    switch (alternativa){
           case 'x' : cout << "\n Jednostrani test " << endl; break;
           case 'y' : cout << "\n Jednostrani test " << endl; break;
           case 'z' : cout << "\n Dvostrani test " << endl; break;
           default : cout << "\n Izbor nije moguc "; return 0;
           }
           
    int n;  
       
    cout << "\n Koliko uzoraka ima?    ";
    cin >> n;
    
    cout << "\n Ako unosite podatke odaberite p, a ako unosite srednju vrijednost birajte s.     Odabrali ste:  ";
    cin >> p_ili_s;
    cout << "\n";
    
    double podaci[n];
    int i;
    double sum=0;
    double x_srednji;
    
    switch (p_ili_s){
           case 'p' : {
                 cout << "\n Unosite vase podatke redom  ";
                 cout  << n ;
                 cout << " \n"<< endl;
                 
                 for (i=0; i<n; ++i) {
                 cin >> podaci[i];
                 sum = sum + podaci[i];
                 }
                  x_srednji=sum/n;
                 } break;
           case 's' : {
                x_srednji;
                cout << "\n Unesite srednju vrijednost:  ";
                cin >> x_srednji; 
                cout << " \n"<< endl;
                }break;
           default : cout << "\n Izbor nije moguc "; return 0;
           }
    
    
    double alfa;
    cout << " Koliko iznosi alfa? ";
    cin >> alfa;
    
    double sigma_da;
    cout << "\n Koliko iznosi disperzija? Ako nepoznata unesite 0. \n Unijeli ste: " ;
    cin >> sigma_da;
    cout << "\n";
    cout << x_srednji<< endl;
    
    if (sigma_da==0) t_test(n, x_srednji, a, alfa, podaci);
    else  u_test(alfa, x_srednji, a, n, sigma_da, alternativa);
         
    system("pause");
    return 0;           
    
}
