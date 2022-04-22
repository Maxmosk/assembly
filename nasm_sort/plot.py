#!/bin/python3
import matplotlib.pyplot as plt


x = []
y = []
with open("data.txt") as f:
    data_sets = f.read().split("\n")

try:
    for this_set in data_sets:
        x.append(0)
        y.append(0)
        print(this_set)
        x[-1], y[-1] = list(this_set.split())
        x[-1] = int(x[-1])
        y[-1] = float(y[-1])
finally:
    plt.scatter(x, y)
    plt.show()

