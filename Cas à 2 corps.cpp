#include <iostream>
#include <cmath>
#include <vector>
#include <fstream>
using namespace std;
double T;
double a;
double G = 6.6743*pow(10, -11);
double M = 100;




// Structure pour représenter un corps céleste
struct Body {
    double x, y, z;  // Position en mètres
    double vx, vy, vz;  // Vitesse en m/s
    //double ax, ay, az; // Accéleration
    double mass;  // Masse en kg
};

// Calcul de la distance entre deux corps
double distance(Body body1, Body body2) {
    return sqrt(pow(body2.x - body1.x, 2) + pow(body2.y - body1.y, 2) + pow(body2.z - body1.z, 2));
}

// Calcul de la force gravitationnelle entre deux corps
void gravitationalForce(Body& body1, Body& body2, double& fx, double& fy, double& fz) {
    double r = distance(body1, body2);  // Distance entre les corps
    double force = G * body1.mass * body2.mass / (r * r);  // Force gravitationnelle
    fx = force * (body2.x - body1.x) / r;
    fy = force * (body2.y - body1.y) / r;
    fz = force * (body2.z - body1.z) / r;
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

    // Constantes
double steps = 100;   // Nombre d'étapes

// Fonction d'évolution
void evolve(double x, double y, double vx, double vy) {
    // Calcul de la distance rint main() {
    
 }

// Méthode RK4
double rk4(double f(double, double), double t, double y, double h) {
  double k1 = f(t, y);
  double k2 = f(t + 0.5*h, y + 0.5*h*k1);
  double k3 = f(t + 0.5*h, y + 0.5*h*k2);
  double k4 = f(t + h, y + h*k3);
  return y + (h/6) * (k1 + 2*k2 + 2*k3 + k4);
}

int main() {
    ofstream PosEurope("Europe.txt");
    // Initialisation des positions et vitesses
    Body europa = { 5.0, 0.0, 0.0, 8.84706, 15.0, 0.0, 0.00253 };  // Europa autour de Jupiter
    Body ganymede = { 7.974966, 0.0, 0.0, 7.00421, 11.0, 0.0, 0.0078};  // Ganymède autour de Jupiter
    Body Jupiter = { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 100}; // Jupiter

    // Paramètres de simulation
    double dt = 10.0;  // Pas de temps en secondes
    int numSteps = 100;  // Nombre d'itérations de simulation

    PosEurope << 't' << '\t' << 'x' << endl;

    // Simulation des mouvements
    for (int i = 0; i < numSteps; ++i) {
        // Calcul des forces entres Ganymède et Europa
        double fx_europa1, fy_europa1, fz_europa1;
        double fx_ganymede1, fy_ganymede1, fz_ganymede1;
        // Calcul des forces entre Jupiter et chaque satellite
        double fx_europa2, fy_europa2, fz_europa2;
        double fx_ganymede2, fy_ganymede2, fz_ganymede2;

        gravitationalForce(europa, ganymede, fx_europa1, fy_europa1, fz_europa1);
        //cout << fx_europa1 << " " << fy_europa1 << " " << fz_europa1 << endl;
        gravitationalForce(ganymede, europa, fx_ganymede1, fy_ganymede1, fz_ganymede1);
        gravitationalForce(europa, Jupiter, fx_europa2, fy_europa2, fz_europa2);
        gravitationalForce(ganymede, Jupiter, fx_ganymede2, fy_ganymede2, fz_ganymede2);

        // Mise à jour des positions et vitesses
        updatePositionVelocity(europa, fx_europa1+fx_europa2, fy_europa1+fy_europa2, fz_europa1+fz_europa2, dt);
        updatePositionVelocity(ganymede, fx_ganymede1+fx_ganymede2, fy_ganymede1+fy_ganymede2, fz_ganymede1+fz_ganymede2, dt);

        // Affichage des positions des satellites
        if (i % 10 == 0) {  // Afficher les positions tous les 10 pas de temps
            cout << "Step " << i << ":\n";
            cout << "Europa: (" << europa.x << ", " << europa.y << ", " << europa.z << ")\n";
            cout << "Ganymede: (" << ganymede.x << ", " << ganymede.y << ", " << ganymede.z << ")\n";
            PosEurope << i << '\t' << europa.x << endl;
        }

        // Conditions initiales
    double x = 1.0;
    double y = 0.0;
    double vx = 0.0;
    double vy = 1.0;

    /*
    for (int i = 0; i < steps; ++i) {
        evolve(x, y, vx, vy);
        cout << "t = " << i*dt << " x = " << x << " y = " << y << endl;
     }
     */
    }
    PosEurope.close();

    return 0;
}