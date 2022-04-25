#!/bin/python3
import datahelp
import math
import matplotlib.pyplot as plt


fig, ax = plt.subplots()

table_data = [[], []]

for file_name in ["data_asm", "data_pas_std", "data_pas_s", "data_pas_1", "data_pas_2", "data_pas_3", "data_pas_4"]:
    x = []
    y = []
    with open(file_name + ".txt") as f:
        data_sets = f.read().split("\n")

    for this_set in data_sets:
        if this_set == "":
            break

        x.append(0)
        y.append(0)
        x[-1], y[-1] = list(this_set.split())
        x[-1] = int(x[-1])
        y[-1] = float(y[-1])
    
    linear_y = list(map(math.sqrt, y)) 
    k, b = datahelp.least_squares_method(x, linear_y)
    table_data[0].append(k)
    table_data[1].append(b)
    print(file_name, round(k, 3), round(b, 3))
    ax.scatter(x, linear_y, s=2)
    ax.plot([min(x), max(x)], [min(x)*k + b, max(x)*k + b], lw=1, label=file_name)

ax.set_title("Bubble sortings comparation")
ax.set_xlabel("Size of sorted array, elements")
ax.set_ylabel("Time of execution, CPU cycles, sqrt")
ax.legend()
plt.show()

