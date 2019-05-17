def quotientList(l1, l2):
    return [a / b for a, b in zip(l1, l2) if b != 0]


a = [1, 2, 3, 5, 6]
b = [2, 1, 3, 0]

c = quotientList(a, b)
print(c)
