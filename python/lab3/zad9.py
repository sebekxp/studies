def checkboard(size):
    return [[(x+1) % 2 if i % 2 == 0 else x % 2 for x in range(size)] for i in range(size)]


print(checkboard(3))
print(checkboard(4))
print(checkboard(5))
