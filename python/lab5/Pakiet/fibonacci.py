def rfib(n):
    if n <= 1:
        return n
    else:
        return rfib(n - 1) + rfib(n - 2)


def ifib(n):
    a, b = 0, 1
    for i in range(1, n - 1):
        a, b = b, a + b
    return a + b
