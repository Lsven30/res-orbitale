import matplotlib.pyplot as plt 
import numpy as np 

# Lecture des fichiers de données
data1 = np.loadtxt('GravIo.txt', skiprows=1)
data2 = np.loadtxt('GravEu.txt', skiprows=1)
data3 = np.loadtxt('GravGa.txt', skiprows=1)
#rk4 data = np.loadtxt('rk4.txt', skiprows=1)
#analytique data = np.loadtxt('theorie.txt', skiprows=1)

#Tracé des graphiques
plt.plot(data1[:, 0], data1[:, 1], label='PosIo', c = 'red')
plt.plot(data2[:, 0], data2[:, 1], label='PosEu', c = 'blue')
plt.plot(data3[:, 0], data3[:, 1], label='PosGa', c = 'green')
#plt.plot(analytique_data[:, 0], analytique_data[:, 1], label='Analytique', c = 'green')

# Configuration du graphique
plt.xlabel('temps en jours')
plt.ylabel('force en mewtons')
plt.title('Résultats de la résolution numérique')
plt.legend()

# Affichage du graphique
plt.show()