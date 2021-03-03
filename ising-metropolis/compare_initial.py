# compare_initial.py

import numpy as np
import matplotlib.pyplot as plt
import os


def compare_initial(beta, n):
    plt.clf()
    fn = "e_t.dat"

    command = "./initial_phase " + str(beta) + ' ' + str(n) + " --random"
    print(command)
    os.system(command)
    e_random = np.genfromtxt(fn)

    command = "./initial_phase " + str(beta) + ' ' + str(n)
    print(command)
    os.system(command)
    e = np.genfromtxt(fn)

    t = np.linspace(0, len(e) - 1, num=len(e))

    plt.plot(t, e_random, label='random initial condition')
    plt.plot(t, e, label=r'Initial state: $m_{ij} = 1$')

    plt.title(rf'Ising model with different initial states with $\beta = {beta:.2f}$')
    plt.legend()
    plt.xscale('log')
    plt.xlabel('# of sweeps')
    plt.ylabel('Energy density')

    plt.savefig('pdf/compare_initial_' + str(beta) + '.pdf')
