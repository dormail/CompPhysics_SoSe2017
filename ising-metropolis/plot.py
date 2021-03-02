# plot.py

import numpy as np
import matplotlib.pyplot as plt
import os

os.system("./ising 1.0")

fn = "e_t.dat"
m = np.genfromtxt(fn)
t = np.linspace(0, len(m)-1, num=len(m))

plt.plot(t, m)
plt.title('e(t) with k_B T = 1.0')

plt.show()
