
import numpy as np
import matplotlib.pyplot as plt

def PlotFromTxt(input, output):
    data = np.genfromtxt(input)

    x = data[0::3]
    y = data[1::3]
    z = data[2::3]

    plt.plot(x, label='x(t)')
    plt.plot(y, label='y(t)')
    plt.plot(z, label='z(t)')
    plt.legend()
    plt.savefig(output)
    plt.clf()


# plotting the euler stuff
PlotFromTxt('res.txt', 'plot.pdf')
