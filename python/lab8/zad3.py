def zakres(number):
    for i in range(number):
        yield i


for i in zakres(10):
    print(i)
