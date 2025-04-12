#include<cmath>

double G=6.6743*pow(10,-11);

double Per(double x, double y, double z)
{return sqrt((pow(z, 3) * 4 * pow(M_PI, 2)) / (G * (x + y)));}



