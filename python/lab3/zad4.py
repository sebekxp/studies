def sumList(l1, l2):
    return [a + b for a, b in zip(l1, l2)]


a = [1, 2, 3, 4, 5]
b = [1, 2, 3, 4, 5]

c = sumList(a, b)
print(c)
