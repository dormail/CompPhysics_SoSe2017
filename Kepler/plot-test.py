# plot-test.py

import numpy as np
import matplotlib.pyplot as plt

fn = 'kepler-test.txt'
data = np.genfromtxt(fn)
data_bad = np.genfromtxt('kepler_v0_7.txt')

x = data[::3]
y = data[1::3]
z = data[2::3]

x_bad = data_bad[::3]
y_bad = data_bad[1::3]

plt.plot(x,y, label='v0=(0,1,0)')
plt.plot(x_bad, y_bad, label='v0 = (0, 0.7, 0)')

plt.grid(True)

plt.show()
