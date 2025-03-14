#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
double T;
double a;
double G = 6.6743*pow(10, -11);
double m;
double M;

int main() {
cout << "Masse de la planète (kg)";
cin >> M;
cout << "Masse du satellite (kg)";
cin >> m;
cout << "Demi-grand axe (m)";
cin >> a;

T = sqrt(4*pow(M_PI, 2)/(G*(M+m))*pow(a, 3));

cout << "Période de révolution (s)" << T/(24*3600) << "jours" << endl;

return 0;

}


