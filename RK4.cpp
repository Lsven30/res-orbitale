#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>


void solution_analytique(double t, double x0, double lambda, double omega_0, double* x, double* z) {
  double omega_prime = sqrt(omega_0*omega_0 - lambda*lambda);
  double B = lambda / omega_prime;

  *x = x0 * exp(-lambda*t) * (cos(omega_prime*t) + B*sin(omega_prime*t));
  *z = -x0 * exp(-lambda*t) * ((lambda*lambda + omega_prime*omega_prime) / omega_prime) * sin(omega_prime*t);
}

void rk1(double t, double x, double z, double h, double& x_next, double& z_next, double lambda, double omega_0) {
  // Calcul des dérivées
  double dxdt = z;
  double dzdt =  - 2*lambda*z - omega_0*omega_0*x;

  // Mise à jour des valeurs de x et z
  x_next = x + h*dxdt;
  z_next = z + h*dzdt;
}

void rk4(double t, double x, double z, double h, double& x_next, double& z_next, double lambda, double omega_0) {
  // Calcul des dérivées
  double k1_x, k1_z, k2_x, k2_z, k3_x, k3_z, k4_x, k4_z;
  double x_mid, z_mid;

  // Étape 1
  k1_x = z;
  k1_z =  - 2*lambda*z - omega_0*omega_0*x;

  // Étape 2
  x_mid = x + 0.5*h*k1_x;
  z_mid = z + 0.5*h*k1_z;
  k2_x = z_mid;
  k2_z =  - 2*lambda*z_mid - omega_0*omega_0*x_mid;

  // Étape 3
  x_mid = x + 0.5*h*k2_x;
  z_mid = z + 0.5*h*k2_z;
  k3_x = z_mid;
  k3_z =  - 2*lambda*z_mid - omega_0*omega_0*x_mid;

  // Étape 4
  x_mid = x + h*k3_x;
  z_mid = z + h*k3_z;
  k4_x = z_mid;
  k4_z =  - 2*lambda*z_mid - omega_0*omega_0*x_mid;

  // Mise à jour des valeurs de x et z
  x_next = x + (h/6.0)*(k1_x + 2*k2_x + 2*k3_x + k4_x);
  z_next = z + (h/6.0)*(k1_z + 2*k2_z + 2*k3_z + k4_z);
}


int main() {
  // Définition des paramètres
  double x0 = 1.0; // position initiale
  double z0 = 0.0; // position initiale
  double lambda = 0.1; // coefficient de frottement
  double omega_0 = 1.0; // pulsation propre
  double dt = 0.01; // pas de temps
  double t_end = 10.0; // temps maximum
  double omega_prime = sqrt(omega_0*omega_0 - lambda*lambda);
  double B = lambda / omega_prime;

  // Création des fichiers de sortie
  std::ofstream fichier_RK1("RK1.txt");
  std::ofstream fichier_RK4("RK4.txt");
  std::ofstream fichier_theorie("theorie.txt");

  // Écriture des entêtes des fichiers
  fichier_RK1 << "t" << "\t" << "x" << std::endl;
  fichier_RK4 << "t" << "\t" << "x" << std::endl;
  fichier_theorie << "t" << "\t" << "x" << std::endl;

  // Initialisation des variables
  double t = 0;
  double x_RK1 = x0;
  double z_RK1 = z0;
  double x_RK4 = x0;
  double z_RK4 = z0;

  // Boucle de résolution
  while (t < t_end) {
    // Résolution via RK1
    rk1(t, x_RK1, z_RK1, dt, x_RK1, z_RK1, lambda, omega_0);

    // Résolution via RK4
    rk4(t, x_RK4, z_RK4, dt, x_RK4, z_RK4, lambda, omega_0);

    // Solution analytique
    double x_theorie = x0 * exp(-lambda*t) * (cos(omega_prime*t) + B*sin(omega_prime*t));

    // Écriture des résultats dans les fichiers
    fichier_RK1 << t << "\t" << x_RK1 << std::endl;
    fichier_RK4 << t << "\t" << x_RK4 << std::endl;
    fichier_theorie << t << "\t" << x_theorie << std::endl;

    // Incrémentation du temps
    t += dt;
  }

  // Fermeture des fichiers
  fichier_RK1.close();
  fichier_RK4.close();
  fichier_theorie.close();

  return 0;
}