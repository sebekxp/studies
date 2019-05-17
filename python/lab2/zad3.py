from numpy import arange
from math import sin


def printFx(fx, start=-1, end=1, num_of_range=10):
    step = (end - start) / num_of_range
    for i in arange(start, end, step):
        print(i, fx(i))


printFx(lambda x: sin(x))
