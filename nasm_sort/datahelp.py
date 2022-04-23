from collections.abc import Iterable
from matplotlib.pyplot import plot as plot, scatter as scatter, show as show


def least_squares_method(x, y):
    assert isinstance(x, Iterable), "It isn't iterable data type"
    assert isinstance(y, Iterable), "It isn't iterable data type"

    x_mean = arith_mean(x)
    y_mean = arith_mean(y)
    x_mult_y_mean = arith_mean([x[i] * y[i] for i in range(len(x))])
    x_square_mean = arith_mean([a**2 for a in x])
    k = (x_mult_y_mean - x_mean * y_mean) / (x_square_mean - x_mean**2)
    b =  y_mean - k * x_mean
    
    return k, b

def arith_mean(data):
    assert isinstance(data, Iterable), "It isn't iterable data type"
    
    return sum(data) / len(data)

def linear_approx(x, y):
    assert isinstance(x, Iterable), "It isn't iterable data type"
    assert isinstance(y, Iterable), "It isn't iterable data type"

    k, b = least_squares_method(x, y)
    
    scatter(x, y)
    plot([min(x), max(x)], [min(x)*k + b, max(x)*k + b])
    show()

    return k, b

