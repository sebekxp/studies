import math


def sin_cos(angle):
    return math.sin(math.radians(angle)), math.cos(math.radians(angle))


angle = 0
print("Kat = {}".format(angle), ", sin = ", sin_cos(angle)[0], ", cos = ", sin_cos(angle)[1])
angle = 45
print("Kat = {}".format(angle), ", sin = ", sin_cos(angle)[0], ", cos = ", sin_cos(angle)[1])
angle = 90
print("Kat = {}".format(angle), ", sin = ", sin_cos(angle)[0], ", cos = ", sin_cos(angle)[1])
