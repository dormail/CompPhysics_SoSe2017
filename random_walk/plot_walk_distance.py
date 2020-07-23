# plot_walk_distance.py start
# python script for plotting the results of the random walk distance test

import numpy as np
import matplotlib.pyplot as plt
import pandas as pd

data = pd.read_csv("random_walk_results.csv")

r = data["r"]
n = data["n"]

plt.plot(n,r)
plt.show()

# plot_walk_distance.py end
