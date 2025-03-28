#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
double T;
double a;
double G = 6.6743*pow(10, -11);
double M = 100;




// Structure pour représenter un corps céleste
struct Body {
    double x, y, z;  // Position en mètres
    double vx, vy, vz;  // Vitesse en m/s
    double mass;  // Masse en kg
};

// Calcul de la distance entre deux corps
double distance(Body body1, Body body2) {
    return sqrt(pow(body2.x - body1.x, 2) + pow(body2.y - body1.y, 2) + pow(body2.z - body1.z, 2));
}

// Calcul de la force gravitationnelle entre deux corps
void gravitationalForce(Body body1, Body body2) {
    double r = distance(body1, body2);  // Distance entre les corps
    double force = G * body1.mass * body2.mass / (r * r);  // Force gravitationnelle
    double fx = force * (body2.x - body1.x) / r;
    double fy = force * (body2.y - body1.y) / r;
    double fz = force * (body2.z - body1.z) / r;
}

// Mise à jour des positions et vitesses selon la méthode d'Euler
void updatePositionVelocity(Body body1, double fx, double fy, double fz, double dt) {
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
double steps = 1000;   // Nombre d'étapes

// Fonction d'évolution
void evolve(double& x, double& y, double& vx, double& vy) {
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
    // Initialisation des positions et vitesses
    Body europa = { 6.0, 0.0, 0.0, 0.0, 15.0, 0.0, 4 };  // Europa autour de Jupiter
    Body ganymede = { 10.0, 0.0, 0.0, 0.0, 11.0, 0.0, 1};  // Ganymède autour de Jupiter
    Body Jupiter = { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 10}; // Jupiter

    // Paramètres de simulation
    double dt = 10.0;  // Pas de temps en secondes
    int numSteps = 100;  // Nombre d'itérations de simulation

    // Simulation des mouvements
    for (int i = 0; i < numSteps; ++i) {
        // Calcul des forces entre Jupiter et chaque satellite
        double fx_europa, fy_europa, fz_europa;
        double fx_ganymede, fy_ganymede, fz_ganymede;

        gravitationalForce(europa, ganymede);
        gravitationalForce(ganymede, europa);

        // Mise à jour des positions et vitesses
        updatePositionVelocity(europa, fx_europa, fy_europa, fz_europa, dt);
        updatePositionVelocity(ganymede, fx_ganymede, fy_ganymede, fz_ganymede, dt);

        // Affichage des positions des satellites (optionnel)
        if (i % 100 == 0) {  // Afficher les positions tous les 100 pas de temps
            cout << "Step " << i << ":\n";
            cout << "Europa: (" << europa.x << ", " << europa.y << ", " << europa.z << ")\n";
            cout << "Ganymede: (" << ganymede.x << ", " << ganymede.y << ", " << ganymede.z << ")\n";
        }

        // Conditions initiales
    double x = 1.0;
    double y = 0.0;
    double vx = 0.0;
    double vy = 1.0;

    for (int i = 0; i < steps; ++i) {
        evolve(x, y, vx, vy);
        cout << "t = " << i*dt << " x = " << x << " y = " << y << endl;
     }
    }

    return 0;
}