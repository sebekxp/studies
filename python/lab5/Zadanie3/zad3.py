import random

jaki = []
kto = []
co_zrobil = []
komu = []
with open("01_jaki.txt", "r") as fjaki:
    for i in fjaki:
        new = i[0:-1]
        jaki.append(new)
with open("02_kto.txt", "r") as fkto:
    for i in fkto:
        new = i[0:-1]
        kto.append(new)
with open("03_co_zrobil.txt", "r") as fco_zrobil:
    for i in fco_zrobil:
        new = i[0:-1]
        co_zrobil.append(new)
with open("04_komu.txt", "r") as fkomu:
    for i in fkomu:
        new = i[0:-1]
        komu.append(new)

with open("wynik.txt", "w") as fwynik:
    for i in range(100):
        fwynik.write(
            f"{i + 1}. {random.choice(jaki)}"
            f" {random.choice(kto)}"
            f" {random.choice(co_zrobil)}"
            f" {random.choice(komu)}\n"
        )
