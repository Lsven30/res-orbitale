#include <iostream>
#include <cmath>
#include <vector>
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
void updatePositionVelocity(Body body1, Body body2, double fx, double fy, double fz, double dt) {
    // Calcul des accélérations
    double ax = fx / body1.mass;
    double ay = fy / body1.mass;
    double az = fz / body1.mass;

    // Mise à jour des vitesses
    body.vx += ax * dt;
    body.vy += ay * dt;
    body.vz += az * dt;

    // Mise à jour des positions
    body.x += body.vx * dt;
    body.y += body.vy * dt;
    body.z += body.vz * dt;
}

int main() {
    // Initialisation des positions et vitesses
    Body europa = { 670900000.0, 0.0, 0.0, 0.0, 15000.0, 0.0, 4.799e22 };  // Europa autour de Jupiter
    Body ganymede = { 1070400000.0, 0.0, 0.0, 0.0, 11000.0, 0.0, 1.4819e23 };  // Ganymède autour de Jupiter

    // Paramètres de simulation
    double dt = 10000.0;  // Pas de temps en secondes
    int numSteps = 10000;  // Nombre d'itérations de simulation

    // Simulation des mouvements
    for (int i = 0; i < numSteps; ++i) {
        // Calcul des forces entre Jupiter et chaque satellite
        double fx_europa, fy_europa, fz_europa;
        double fx_ganymede, fy_ganymede, fz_ganymede;

        gravitationalForce(europa, ganymede, fx_europa, fy_europa, fz_europa);
        gravitationalForce(ganymede, europa, fx_ganymede, fy_ganymede, fz_ganymede);

        // Mise à jour des positions et vitesses
        updatePositionVelocity(europa, fx_europa, fy_europa, fz_europa, dt);
        updatePositionVelocity(ganymede, fx_ganymede, fy_ganymede, fz_ganymede, dt);

        // Affichage des positions des satellites (optionnel)
        if (i % 100 == 0) {  // Afficher les positions tous les 100 pas de temps
            std::cout << "Step " << i << ":\n";
            std::cout << "Europa: (" << europa.x << ", " << europa.y << ", " << europa.z << ")\n";
            std::cout << "Ganymede: (" << ganymede.x << ", " << ganymede.y << ", " << ganymede.z << ")\n";
        }
    }

    return 0;
}