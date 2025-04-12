#include <iostream>
#include <cmath>
#include <vector>
#include<fstream>
using namespace std;
double T;
double a;
double G = 6.6743*pow(10, -11);
double M = 1.898e27;



// Structure pour représenter un corps céleste
struct Body {
    double x, y, z;  // Position en mètres
    double vx, vy, vz;  // Vitesse en m/s
    double mass;  // Masse en kg
};

// Calcul de la distance entre deux corps
double distance(Body body1, Body body2) {
    return sqrt((body2.x - body1.x)*(body2.x - body1.x) + (body2.y - body1.y)*(body2.y - body1.y) + (body2.z - body1.z)*(body2.z - body1.z));
}

// Calcul de la force gravitationnelle entre deux corps
void gravitationalForce(Body body1, Body body2, double& fx, double& fy, double& fz, double& force) {
    double r = distance(body1, body2);  // Distance entre les corps
    force = G*body1.mass * body2.mass / (r * r);  // Force gravitationnelle
    fx =  force * (body2.x - body1.x) / r;
    fy =  force * (body2.y - body1.y) / r;
    fz =  force * (body2.z - body1.z) / r;
}

// Mise à jour des positions et vitesses selon la méthode d'Euler
void updatePositionVelocity(Body& body1, double fx, double fy, double fz, double dt) {
    // Calcul des accélérations
    double ax = fx / body1.mass;
    double ay = fy / body1.mass;
    double az = fz / body1.mass;

    // Mise à jour des vitesses
    body1.vx += ax * dt;
    body1.vy += ay * dt;
    body1.vz += az * dt;

    // Mise à jour des positions
    body1.x += body1.vx * dt;
    body1.y += body1.vy * dt;
    body1.z += body1.vz * dt;
}

int main() {
    // Initialisation des positions et vitesses
    Body europa = { 671900e3, 0.0, 0.0, 0.0, 13740, 0.0, 4.799e22};  // Europa autour de Jupiter
    Body ganymede = { 1070400e3, 0.0, 0.0, 0.0, 10883, 0.0, 1.482e23 };  // Ganymède autour de Jupiter
    Body Jupiter = { 0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.898e27};  // Jupiter
    double fx_europa = 0, fy_europa  = 0, fz_europa = 0, f_europa=0;
    double fx_ganymede = 0, fy_ganymede = 0, fz_ganymede = 0,f_ganymede=0;

    ofstream PosEu("XposEu.txt"); //creation fichier position Europe
    ofstream PosGa("XposGa.txt"); //creation fichier position Ganymède
    PosEu<< "t" << "\t" << "x" << endl;
    PosGa<< "t" << "\t" << "x" << endl;
    // Paramètres de simulation
    double dt = 5000;  // Pas de temps en secondes
    int numSteps = 200;  // Nombre d'itérations de simulation

    // Simulation des mouvements
    for (int i = 0; i < numSteps; ++i) {
        // Calcul des forces entre Jupiter et chaque satellite
        

        gravitationalForce(europa, Jupiter, fx_europa, fy_europa, fz_europa, f_europa);
        gravitationalForce(ganymede, Jupiter, fx_ganymede, fy_ganymede, fz_ganymede, f_ganymede);

        // Mise à jour des positions et vitesses
        updatePositionVelocity(europa, fx_europa, fy_europa, fz_europa, dt);
        updatePositionVelocity(ganymede, fx_ganymede, fy_ganymede, fz_ganymede, dt);
        PosEu  << (i*dt)/86400 << "\t" << europa.x/1000<< endl;
        PosGa  << (i*dt)/86400 << "\t" << ganymede.x/1000<< endl;
        
        /*
        // Affichage des positions des satellites (optionnel)
        if (i % 100 == 0) {  // Afficher les positions tous les 100 pas de temps
            std::cout << "Step " << i << ":\n";
            std::cout << "Europa: (" << europa.x << ", " << europa.y << ", " << europa.z << ")\n";
            std::cout << "Ganymede: (" << ganymede.x << ", " << ganymede.y << ", " << ganymede.z << ")\n";
        }
            */
    }
    PosEu.close();
    PosGa.close();
    return 0;
}