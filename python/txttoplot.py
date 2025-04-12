import matplotlib.pyplot as plt
import numpy as np

monfichier1 = "/home/lsven03lnx/c++/MonProjet/txt/RK4.txt"
#monfichier2 = "/home/lsven03lnx/c++/MonProjet/txt/Valtheo.txt"
#monfichier3 = "/home/lsven03lnx/c++/MonProjet/txt/RK1.txt"
# On lit les fichiers (transforme le texte en tableau numpy)
data1 = np.loadtxt(monfichier1)
#data2 = np.loadtxt(monfichier2)
#data3 = np.loadtxt(monfichier3)

# On trace
# data1[:, 0] signifie "toutes les lignes de la 1 ère colonne
plt.plot(data1[:, 0], data1[:, 1], label='RK4', c='red')
plt.plot(data3[:, 0], data3[:, 1], label='RK1', c='blue')
plt.plot(data2[:, 0], data2[:, 1], label='théo', c='green')
# Des décorations
plt.xlabel('t')
plt.ylabel('y')
plt.title('Résultats')
plt.legend() #pour que les label soient visibles

# Affichage
plt.show()