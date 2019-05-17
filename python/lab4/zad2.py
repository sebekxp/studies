def fun(a, b):
    return b, a + b


def fib(n):
    k = (0, 1)
    for i in range(n):
        k = fun(*k)
    return k[0]


print(fib(8))
