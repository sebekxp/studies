def srednia():
    list = []
    while True:
        a = (yield)
        list.append(a)
        yield sum(list) / len(list)


generator = srednia()
for i in [1, 2, 3, 4, 5, 6, 7]:
    next(generator)
    print(generator.send(i))
