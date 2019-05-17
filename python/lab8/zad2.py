class Unikalne:
    def __init__(self, list):
        self.unique = set(list)
        self.it = iter(self.unique)

    def __iter__(self):
        return self

    def __next__(self):
        return next(self.it)


l = [1, 2, 1, 3, 4, 5, 5]
u = Unikalne(l)
for i in u:
    print(i)
