
import numpy as np
import matplotlib.pyplot as plt

fn = 'res.txt'
data = np.genfromtxt(fn)

x = data[0::3]
y = data[1::3]
z = data[2::3]

plt.plot(x, label='x(t)')
plt.plot(y, label='y(t)')
plt.plot(z, label='z(t)')
plt.legend()
plt.savefig('plot.pdf')