
import numpy as np
import matplotlib.pyplot as plt


def PlotFromTxt(input, output):
    data = np.genfromtxt(input)

    x = data[0::4]
    y = data[1::4]
    z = data[2::4]
    E = data[3::4]

    plt.plot(x, label='x(t)')
    # plt.plot(y, label='y(t)')
    # plt.plot(z, label='z(t)')
    plt.plot(E, label='E(t)')

    plt.xlabel('# of integration steps')

    plt.legend()
    plt.savefig(output)
    plt.clf()


# plotting the euler stuff
PlotFromTxt('res.txt', 'plot.pdf')
PlotFromTxt('runge-kutta2.txt', 'runge-kutta2.pdf')
