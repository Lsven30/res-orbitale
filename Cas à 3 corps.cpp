#include <iostream>
#include <cmath>
#include <vector>
#include <fstream>
//#include "RK4-app.cpp"
using namespace std;
double T;
double a;
double G = 6.6743*pow(10, -11);


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
// double steps = 100;   // Nombre d'étapes

// Fonction d'évolution
void evolve(double x, double y, double vx, double vy) {
    // Calcul de la distance rint main() {
    
 }

// Méthode RK4
void compute_acceleration(const Body& body1, double& ax, double& ay) {
    double dx = -body1.x;
    double dy = -body1.y;
    double r = sqrt(dx*dx + dy*dy);
    double MJ = 1.898*pow(10, 27);
    double a = G * MJ / (r * r);

    ax = a * dx / r;
    ay = a * dy / r;
}

void updatePositionVelocity2(Body& body1, double fx, double fy, double fz, double dt) {
    double ax1, ay1, ax2, ay2, ax3, ay3, ax4, ay4;
    
    // Étape 1
    compute_acceleration(body1, ax1, ay1);
    double k1vx = ax1 * dt;
    double k1vy = ay1 * dt;
    double k1x = body1.vx * dt;
    double k1y = body1.vy * dt;

    // Étape 2
    Body temp = body1;
    temp.vx += 0.5 * k1vx;
    temp.vy += 0.5 * k1vy;
    temp.x += 0.5 * k1x;
    temp.y += 0.5 * k1y;
    compute_acceleration(temp, ax2, ay2);
    double k2vx = ax2 * dt;
    double k2vy = ay2 * dt;
    double k2x = temp.vx * dt;
    double k2y = temp.vy * dt;

    // Étape 3
    temp = body1;
    temp.vx += 0.5 * k2vx;
    temp.vy += 0.5 * k2vy;
    temp.x += 0.5 * k2x;
    temp.y += 0.5 * k2y;
    compute_acceleration(temp, ax3, ay3);
    double k3vx = ax3 * dt;
    double k3vy = ay3 * dt;
    double k3x = temp.vx * dt;
    double k3y = temp.vy * dt;

    // Étape 4
    temp = body1;
    temp.vx += k3vx;
    temp.vy += k3vy;
    temp.x += k3x;
    temp.y += k3y;
    compute_acceleration(temp, ax4, ay4);
    double k4vx = ax4 * dt;
    double k4vy = ay4 * dt;
    double k4x = temp.vx * dt;
    double k4y = temp.vy * dt;

    // Mise à jour finale
    body1.vx += (k1vx + 2*k2vx + 2*k3vx + k4vx) / 6.0;
    body1.vy += (k1vy + 2*k2vy + 2*k3vy + k4vy) / 6.0;
    body1.x += (k1x + 2*k2x + 2*k3x + k4x) / 6.0;
    body1.y += (k1y + 2*k2y + 2*k3y + k4y) / 6.0;
}

int main() {
    int choix;
    cout << "Veuillez entrer 0 pour méthode d'Euler ou 1 pour méthode RK4 : " << endl;
    cin >> choix;
    while (choix!= 0 and choix != 1){
        cout << "Veuillez entrer 0 pour méthode d'Euler ou 1 pour méthode RK4 : " << endl;
        cin >> choix;
    }
    ofstream PosIo("Io.txt");
    ofstream PosEurope("Europe.txt");
    ofstream PosGanymede("Ganymede.txt");
    ofstream gravio("GravIo.txt");
    ofstream graveu("GravEu.txt");
    ofstream gravga("GravGa.txt");
    // Initialisation des positions et vitesses
    // Body io = {1, 0, 0, 5, 11, 0, 0.0011}; // Io autour de Jupiter
    // Body europa = { 5.0, 0.0, 0.0, 8.84706, 15.0, 0.0, 0.00253 };  // Europa autour de Jupiter
    // Body ganymede = { 7.974966, 0.0, 0.0, 7.00421, 11.0, 0.0, 0.0078};  // Ganymède autour de Jupiter
    // Body Jupiter = { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 100}; // Jupiter
    
    double vioref=-17324.38;
    double veuref=13740.3;
    double vgaref=10883.53;
    Body europa = { 671900e3, 0.0, 0.0, 0.0, veuref, 0.0, 4.799e22};  // Europa autour de Jupiter
    Body ganymede = { 1070400e3, 0.0, 0.0, 0.0, vgaref, 0.0, 1.482e23 };  // Ganymède autour de Jupiter
    Body io = { -421800e3, 0.0, 0.0, 0.0, vioref, 0.0, 8.93e22 };  // Io autour de Jupiter
    Body Jupiter = { 0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.898e27};  // Jupiter
    
    // Paramètres de simulation
    double dt = 1000.0;  // Pas de temps en secondes
    int numSteps = 1000;  // Nombre d'itérations de simulation

    PosIo << 't' << '\t' << 'x' << endl;
    PosEurope << 't' << '\t' << 'x' << endl;
    PosGanymede << 't' << '\t' << 'x' << endl;

    // Simulation des mouvements
    for (int i = 0; i < numSteps; ++i) {
        // Calcul des forces entres Ganymède et Europa
        double fx_europa1, fy_europa1, fz_europa1;
        double fx_ganymede1, fy_ganymede1, fz_ganymede1;
        // Calcul des forces entre Jupiter et chaque satellite
        double fx_europa2, fy_europa2, fz_europa2;
        double fx_ganymede2, fy_ganymede2, fz_ganymede2;
        double fx_io2, fy_io2, fz_io2;
        // Calcul forces entre Io et Europa
        double fx_europa3, fy_europa3, fz_europa3;
        double fx_io1, fy_io1, fz_io1;
         // Calcul forces entre Io et Ganymède
        double fx_ganymede3, fy_ganymede3, fz_ganymede3;
        double fx_io3, fy_io3, fz_io3;

        gravitationalForce(europa, ganymede, fx_europa1, fy_europa1, fz_europa1);
        //cout << fx_europa1 << " " << fy_europa1 << " " << fz_europa1 << endl;
        gravitationalForce(ganymede, europa, fx_ganymede1, fy_ganymede1, fz_ganymede1);
        gravitationalForce(europa, Jupiter, fx_europa2, fy_europa2, fz_europa2);
        gravitationalForce(ganymede, Jupiter, fx_ganymede2, fy_ganymede2, fz_ganymede2);
        gravitationalForce(io, Jupiter, fx_io2, fy_io2, fz_io2);
        gravitationalForce(europa, io, fx_europa3, fy_europa3, fz_europa3);
        gravitationalForce(europa, io, fx_io1, fy_io1, fz_io1);
        gravitationalForce(ganymede, io, fx_ganymede3, fy_ganymede3, fz_ganymede3);
        gravitationalForce(ganymede, io, fx_io3, fy_io3, fz_io3);

        // Mise à jour des positions et vitesses
        if (choix == 0) {
        updatePositionVelocity(io, fx_io1+fx_io2+fx_io3, fy_io1+fy_io2+fy_io3, fz_io1+fz_io2+fz_io3, dt);
        updatePositionVelocity(europa, fx_europa1+fx_europa2+fx_europa3, fy_europa1+fy_europa2+fy_europa3, fz_europa1+fz_europa2+fz_europa3, dt);
        updatePositionVelocity(ganymede, fx_ganymede1+fx_ganymede2+fx_ganymede3, fy_ganymede1+fy_ganymede2+fy_ganymede3, fz_ganymede1+fz_ganymede2+fz_ganymede3, dt);
        gravio  << (i*dt)/86400<< "\t" << G* europa.mass * io.mass / (distance(europa,io)*distance(europa,io)) + G* ganymede.mass * io.mass / (distance(ganymede,io)*distance(ganymede,io))<< endl;
        graveu  << (i*dt)/86400<< "\t" << G* europa.mass * io.mass / (distance(europa,io)*distance(europa,io)) + G* europa.mass * ganymede.mass / (distance(europa,ganymede)*distance(europa,ganymede)) << endl;
        gravga  << (i*dt)/86400<< "\t" << G* io.mass * ganymede.mass / (distance(io,ganymede)*distance(io,ganymede)) + G* europa.mass * ganymede.mass / (distance(europa,ganymede)*distance(europa,ganymede)) << endl;
        }
        if (choix == 1) {
        updatePositionVelocity2(io, fx_io1+fx_io2+fx_io3, fy_io1+fy_io2+fy_io3, fz_io1+fz_io2+fz_io3, dt);
        updatePositionVelocity2(europa, fx_europa1+fx_europa2+fx_europa3, fy_europa1+fy_europa2+fy_europa3, fz_europa1+fz_europa2+fz_europa3, dt);
        updatePositionVelocity2(ganymede, fx_ganymede1+fx_ganymede2+fx_ganymede3, fy_ganymede1+fy_ganymede2+fy_ganymede3, fz_ganymede1+fz_ganymede2+fz_ganymede3, dt);
        gravio  << (i*dt)/86400<< "\t" << G* europa.mass * io.mass / (distance(europa,io)*distance(europa,io)) + G* ganymede.mass * io.mass / (distance(ganymede,io)*distance(ganymede,io))<< endl;
        graveu  << (i*dt)/86400<< "\t" << G* europa.mass * io.mass / (distance(europa,io)*distance(europa,io)) + G* europa.mass * ganymede.mass / (distance(europa,ganymede)*distance(europa,ganymede)) << endl;
        gravga  << (i*dt)/86400<< "\t" << G* io.mass * ganymede.mass / (distance(io,ganymede)*distance(io,ganymede)) + G* europa.mass * ganymede.mass / (distance(europa,ganymede)*distance(europa,ganymede)) << endl;
        }

        // Affichage des positions des satellites
        // Afficher les positions pour chaque step
            cout << "Step " << i << ":\n";
            cout << "Io: (" << io.x << ", " << io.y << ", " << io.z << ")\n";
            cout << "Europa: (" << europa.x << ", " << europa.y << ", " << europa.z << ")\n";
            cout << "Ganymede: (" << ganymede.x << ", " << ganymede.y << ", " << ganymede.z << ")\n";
            PosIo << i*dt/86400 << '\t' << io.x/1000 << endl;
            PosEurope << i*dt/86400 << '\t' << europa.x/1000 << endl;
            PosGanymede << i*dt/86400 << '\t' << ganymede.x/1000 << endl;
        

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
    PosIo.close();
    PosEurope.close();
    PosGanymede.close();
    gravio.close();
    graveu.close();
    gravga.close();

    return 0;
}