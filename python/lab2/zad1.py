def mersenneNumber(p):
    return 2 ** p - 1


def isPrimeNumber(num):
    if num > 1:
        for it in range(2, num):
            if (num % it) == 0:
                return False
        else:
            return True
    else:
        return False


for i in range(1, 32):
    mersenne = mersenneNumber(i)
    if isPrimeNumber(mersenne):
        print('\033[93m' + 'M(', i, ") = ", mersenne, '\033[0m')
    else:
        print('M(', i, ") = ", mersenne,)
