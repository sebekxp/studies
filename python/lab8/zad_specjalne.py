x = 0

def bla():
    x = (yield)
    x += 1
    yield x


print(x)
bla()
print(x)
