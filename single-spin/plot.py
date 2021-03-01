# plot.py

import numpy as np
import matplotlib.pyplot as plt

fn = "result.txt"
m = np.genfromtxt(fn)
H = np.linspace(-5, 5, num=len(m))

plt.plot(H, m)
plt.show()