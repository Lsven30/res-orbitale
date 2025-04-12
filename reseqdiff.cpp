#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>


//void solution_analytique(double t, double x0, double lambda, double omega_0, double* x, double* z) {
//  double omega_prime = sqrt(omega_0*omega_0 - lambda*lambda);
//  double B = lambda / omega_prime;
//
//  *x = x0 * exp(-lambda*t) * (cos(omega_prime*t) + B*sin(omega_prime*t));
//  *z = -x0 * exp(-lambda*t) * ((lambda*lambda + omega_prime*omega_prime) / omega_prime) * sin(omega_prime*t);
//}

void rk1(double t, double x, double y, double w, double j, double h, double& x_next, double& y_next, double& w_next, double& j_next) {
    // Calcul des dérivées
    double dxdt = w;
    double dwdt = -100.0/pow(x*x+y*y,1.5);
    double dydt = j;
    double djdt = -100.0/pow(x*x+y*y,1.5);
  
    // Mise à jour des valeurs de x et z
    x_next = x + h*dxdt;
    w_next = w + h*dwdt;
    y_next = y + h*dydt;
    j_next = j + h*djdt;
}
int main() {
  // Définition des paramètres
  double x0 = 5.0; // position initiale x
  double y0 = 0; // position initiale y
  double w0 = 0; // vitesse initiale x
  double j0 = 0.002; // vitesse initiale y
  double dt = 0.01; // pas de temps
  double t_end = 10.0; // temps maximum

  // Création des fichiers de sortie
  std::ofstream fichier_RK1("RK1.txt");
  //std::ofstream fichier_RK4("RK4.txt");

  // Écriture des entêtes des fichiers
  fichier_RK1 << "t" << "\t" << "x" << std::endl;
  //fichier_RK4 << "t" << "\t" << "x" << std::endl;

  // Initialisation des variables
  double t = 0;
  double x_RK1 = x0;
  double w_RK1 = w0;
  double y_RK1 = y0;
  double j_RK1 = j0;
  //double x_RK4 = x0;
  //double z_RK4 = z0;

  // Boucle de résolution
  while (t < t_end) {
    // Résolution via RK1
    rk1(t, x_RK1, y_RK1, w_RK1, j_RK1, dt, x_RK1, y_RK1, w_RK1, j_RK1);

    // Résolution via RK4
    //rk4(t, x_RK4, z_RK4, dt, x_RK4, z_RK4, lambda, omega_0);

    // Solution analytique
    // x_theorie = x0 * exp(-lambda*t) * (cos(omega_prime*t) + B*sin(omega_prime*t));

    // Écriture des résultats dans les fichiers
    fichier_RK1 << t << "\t" << x_RK1 << std::endl;
    //fichier_RK4 << t << "\t" << x_RK4 << std::endl;

    // Incrémentation du temps
    t += dt;
  }

  // Fermeture des fichiers
  fichier_RK1.close();
  //fichier_RK4.close();
  //fichier_theorie.close();

  return 0;
}