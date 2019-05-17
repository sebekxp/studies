import random


def k4():
    return random.randint(1, 4)


def k8():
    return random.randint(1, 8)


def k10():
    return random.randint(1, 10)


def k20():
    return random.randint(1, 20)


def getDice(fun):
    if fun == 'k4':
        return k4()
    elif fun == 'k8':
        return k8()
    elif fun == 'k10':
        return k10()
    else:
        return k20()


def rollDice(str):
    arr = str.split('k')
    sum = 0
    for i in range(int(arr[0])):
        sum += getDice('k' + arr[1])
    return sum


print(rollDice("1k4"))
print(rollDice("2k10"))
print(rollDice("4k8"))
print(rollDice("10k4"))
print(rollDice("100k4"))
print(rollDice("1k7"))
print(rollDice("0k4"))



