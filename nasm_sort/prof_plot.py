#!/bin/python3
import datahelp
import math


x = []
y = []
with open("data.txt") as f:
    data_sets = f.read().split("\n")

for this_set in data_sets:
    if this_set == "":
        break

    x.append(0)
    y.append(0)
    x[-1], y[-1] = list(this_set.split())
    x[-1] = int(x[-1])
    y[-1] = float(y[-1])

datahelp.linear_approx(x, list(map(math.sqrt, y)))

