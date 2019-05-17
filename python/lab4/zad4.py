def func(d):
    return sorted(d.items())


def rnd(d):
    return [i for i in d.items()]


d = {
    'Sebastian': 4,
    'Alek': 4,
    'Pawel': 5,
    'Krystian': 3,
    'Mateusz': 4
}

print(func(d))
print(rnd(d))
