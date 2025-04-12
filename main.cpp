#include <iostream>
#include <cmath>
#include "dataJ.hpp"
#include "kepler.hpp"


using namespace std;


int main() {
    double T;
    double a;
    double M;
    double m;

    cout << "Masse principale (kg) : ";
    cin >> M;
    cout << "Masse corps orbiteur (kg) : ";
    cin >> m;
    cout << "Demi-grand axe (m) : ";
    cin >> a;
   
    T = Per(M,m,a);

    cout << "Période de révolution (s) : " << T/(24*3600) << " jours " << endl;

    return 0;
}


