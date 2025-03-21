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
    double x, y;  // Position en mètres
    double vx, vy;  // Vitesse en m/s
    double mass;  // Masse en kg
}

// Calcul de la distance entre deux corps
double distance(Body body1, Body body2) {
    return sqrt(pow(body2.x - body1.x, 2) + pow(body2.y - body1.y, 2));
}

// Calcul de la force gravitationnelle entre deux corps
void gravitationalForce(Body body1, Body body2) {
    double r = distance(body1, body2);  // Distance entre les corps
    double force = G * body1.mass * body2.mass / (r * r);  // Force gravitationnelle
    double fx = force * (body2.x - body1.x) / r;
    double fy = force * (body2.y - body1.y) / r;
    // double fz = force * (body2.z - body1.z) / r;
}

// Mise à jour des positions et vitesses selon la méthode d'Euler
void updatePositionVelocity(Body body1, Body body2, double fx, double fy, double dt) {
    // Calcul des accélérations
    double ax = fx / body1.mass;
    double ay = fy / body1.mass;
    //double az = fz / body1.mass;

    // Mise à jour des vitesses
    body.vx += ax * dt;
    body.vy += ay * dt;
    //body.vz += az * dt;

    // Mise à jour des positions
    body.x += body.vx * dt;
    body.y += body.vy * dt;
    //body.z += body.vz * dt;
}

int main() {
    // Initialisation des positions et vitesses
    Body europa = { 3, 0.0, 0.0, 0.0, 2};  // Europa autour de Jupiter
    Body ganymede = { 5, 0.0, 0.0, 0.0, 2};  // Ganymède autour de Jupiter
    Body Jupiter = { 0.0, 0.0, 0.0, 0.0, 100 };  // Jupiter

    // Paramètres de simulation
    double dt = 10000.0;  // Pas de temps en secondes
    int numSteps = 10000;  // Nombre d'itérations de simulation

    // Simulation des mouvements
    //for (int i = 0; i < numSteps; ++i) {
        // Calcul des forces entre Jupiter et chaque satellite 
        //double fx_europa, fy_europa;
        //double fx_ganymede, fy_ganymede;

        //gravitationalForce(Jupiter, ganymede);
        //gravitationalForce(Jupiter, europa);

        // Mise à jour des positions et vitesses
        //updatePositionVelocity(europa, fx_europa, fy_europa, dt);
        //updatePositionVelocity(ganymede, fx_ganymede, fy_ganymede,, dt);

        // Affichage des positions des satellites (optionnel)
        //if (i % 100 == 0) {  // Afficher les positions tous les 100 pas de temps
        //    cout << "Step " << i << ":\n";
        //    cout << "Europa: (" << europa.x << ", " << europa.y << ")\n";
        //    cout << "Ganymede: (" << ganymede.x << ", " << ganymede.y << ")\n";
        //}
    }

    return 0;


