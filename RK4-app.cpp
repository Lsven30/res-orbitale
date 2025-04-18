#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>
using namespace std;


const double G = 6.67430e-11; // constante gravitationnelle
const double MJ = 1.898e27;   // masse de Jupiter en kg

// Données approximatives
const double m_Io = 8.93e22;
const double m_Europe = 4.80e22;
const double m_Ganymede = 1.48e23;

const double r_Io = 4.22e8;     // distance moyenne à Jupiter (m)
const double v_Io = 1.74e4;     // vitesse orbitale moyenne (m/s)

const double r_Europe = 6.71e8;
const double v_Europe = 1.31e4;

const double r_Ganymede = 1.07e9;
const double v_Ganymede = 1.08e4;

struct Satellite {
    double x, y;
    double vx, vy;
    double m;
};

void compute_acceleration(const Satellite& sat, double& ax, double& ay) {
    double dx = -sat.x;
    double dy = -sat.y;
    double r = sqrt(dx*dx + dy*dy);
    double a = G * MJ / (r * r);

    ax = a * dx / r;
    ay = a * dy / r;
}

void rk4(Satellite& sat, double dt) {
    double ax1, ay1, ax2, ay2, ax3, ay3, ax4, ay4;
    
    // Étape 1
    compute_acceleration(sat, ax1, ay1);
    double k1vx = ax1 * dt;
    double k1vy = ay1 * dt;
    double k1x = sat.vx * dt;
    double k1y = sat.vy * dt;

    // Étape 2
    Satellite temp = sat;
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
    temp = sat;
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
    temp = sat;
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
    sat.vx += (k1vx + 2*k2vx + 2*k3vx + k4vx) / 6.0;
    sat.vy += (k1vy + 2*k2vy + 2*k3vy + k4vy) / 6.0;
    sat.x += (k1x + 2*k2x + 2*k3x + k4x) / 6.0;
    sat.y += (k1y + 2*k2y + 2*k3y + k4y) / 6.0;
}

Satellite Io = {r_Io, 0, 0, v_Io, m_Io};
Satellite Europe = {r_Europe, 0, 0, v_Europe, m_Europe};
Satellite Ganymede = {r_Ganymede, 0, 0, v_Ganymede, m_Ganymede};

int main() {
  double t = 0.0;
  double dt = 10.0; // en secondes
  double t_end = 60.0 * 60.0 * 24.0 * 100; // 100 jours

  ofstream file("orbits.txt");

  // Boucle de résolution
  while (t < t_end) {
      rk4(Io, dt);
      rk4(Europe, dt);
      rk4(Ganymede, dt);

    file << t << "\t"
         << Io.x << "\t" << Io.y << "\t"
         << Europe.x << "\t" << Europe.y << "\t"
         << Ganymede.x << "\t" << Ganymede.y << "\n";

    t += dt;
  }

    // Fermeture fichier

  return 0;
}