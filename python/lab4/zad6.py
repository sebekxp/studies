import math


def timesleep(d):
    new = {key: (8 / math.log10(value * 8765.81277))
    if value < 200
    else 'inf'
           for key, value in d.items() if value > 0}
    return new


dict = {
    'Sebastian': 357,
    'Pawel': 34,
    'Krystian': 4,
    'Janek': 20,
    'Mateusz': -7
}
print(timesleep(dict))
