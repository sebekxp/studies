import time


def printCenter(str, width_line=80):
    print(str.center(width_line, ' '))


def credits(*args, **kwargs):
    for j in args:
        printCenter(j)
        time.sleep(1)

    for key, value in kwargs.items():
        printCenter("{} = {}".format(key, value))
        time.sleep(1)


credits("Cudowniejszy program pokazowy",
        "Powrót złego Markiza Cul-de-Sac",
        Scenariusz="Sebastian",
        Scenografia="Paszyński",
        Podziekowania="Python")
