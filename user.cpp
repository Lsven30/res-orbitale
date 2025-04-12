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
  