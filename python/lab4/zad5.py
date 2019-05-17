def func(d):
    for key, value in d.items():
        s = 0
        for j in value.values():
            s += j
        avg = s / len(value.values())
        if avg < 3.0:
            print("Imie: ", key, ", Srednia ocen: ", avg)


def z_jednej_kat(str, d):
    s = 0
    counter = 0
    for key, value in d.items():
        for i, j in value.items():
            if i == str:
                s += j
                counter += 1
    return s / counter


d = {
    'Sebastian': {'Python': 4, 'Lisp': 3, 'Egzamin': 2, 'Odpowiedz': 5},
    'Krystian': {'Python': 4, 'Lisp': 5, 'Egzamin': 3, 'Odpowiedz': 2},
    'Pawel': {'Python': 5, 'Lisp': 2, 'Egzamin': 5, 'Odpowiedz': 4},
    'Mateusz': {'Python': 2, 'Lisp': 2, 'Egzamin': 2, 'Odpowiedz': 2},
    'Kamil': {'Python': 3, 'Lisp': 3, 'Egzamin': 4, 'Odpowiedz': 3},
}

func(d)
print("Python: ", z_jednej_kat('Python', d))
print("Lisp: ", z_jednej_kat('Lisp', d))
print("Egzamin: ", z_jednej_kat('Egzamin', d))
print("Odpowiedz: ", z_jednej_kat('Odpowiedz', d))
