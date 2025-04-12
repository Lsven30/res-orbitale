import matplotlib.pyplot as plt
import numpy as np

# Lecture des fichiers de données
data1 = np.loadtxt('XposEu.txt', skiprows=1)
data2 = np.loadtxt('XposGa.txt', skiprows=1)
#rk4_data = np.loadtxt('rk4.txt', skiprows=1)
#analytique_data = np.loadtxt('theorie.txt', skiprows=1)

# Tracé des graphiques
plt.plot(data1[:, 0], data1[:, 1], label='Europe', c='green')
plt.plot(data2[:, 0], data2[:, 1], label='Ganymède', c='red')
#plt.plot(rk4_data[:, 0], rk4_data[:, 1], label='RK4', c='blue')
#plt.plot(analytique_data[:, 0], analytique_data[:, 1], label='Analytique', c='green')

# Configuration du graphique
plt.xlabel('temps (jours)')
plt.ylabel('position x (km)')
plt.title('positions x satellites')
plt.legend()
plt.grid(True)

# Affichage du graphique
plt.show()