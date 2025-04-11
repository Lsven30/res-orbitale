import matplotlib.pyplot as plt 
import numpy as np 

# Lecture des fichiers de données
data1 = np.loadtxt('Europe.txt', skiprows=1)
#rk4 data = np.loadtxt('rk4.txt', skiprows=1)
#analytique data = np.loadtxt('theorie.txt', skiprows=1)

#Tracé des graphiques
plt.plot(data1[:, 0], data1[:, 1], label='PosX', c = 'red')
#plt.plot(analytique_data[:, 0], analytique_data[:, 1], label='Analytique', c = 'green')

# Configuration du graphique
plt.xlabel('t')
plt.ylabel('x')
plt.title('Résultats de la résolution numérique')
plt.legend()

# Affichage du graphique
plt.show()