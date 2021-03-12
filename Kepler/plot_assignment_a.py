import numpy as np
import matplotlib.pyplot as plt

fn = 'dir_a/v_07.txt'
data = np.genfromtxt(fn)
x1 = data[::3]
y1 = data[1::3]

fn = 'dir_a/v_1.txt'
data = np.genfromtxt(fn)
x2 = data[::3]
y2 = data[1::3]

plt.plot(x1, y1, label='v0=(0, 0.7, 0)')
plt.plot(x2, y2, label='v0 = (0, 1, 0)')

plt.grid(True)
plt.legend()

plt.show()
