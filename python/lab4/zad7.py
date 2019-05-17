import random

WINCONDITION = 3


def make_arr(size):
    return [[0 for x in range(size)] for i in range(size)]


def make_cell_true():
    for i in range(WINCONDITION):
        while True:
            cord = random.randint(0, 9), random.randint(0, 9)
            if arr[cord[0]][cord[1]] == 0:
                arr[cord[0]][cord[1]] = 1
                break


arr = make_arr(10)
make_cell_true()

for i in arr:
    print(i)

SET = set()
counter = 0
while True:
    cords = (int(input("Cord X: ")), int(input("Cord Y: ")))
    if cords in SET:
        print("Juz tam strzelano")
        continue
    SET.add(cords)
    if not (0 <= cords[0] <= 9) or not (0 <= cords[1] <= 9):
        print("Index should be in range <0, 9>")
        continue
    elif arr[cords[0]][cords[1]] == 1:
        print("Trafiony")
        counter += 1
    else:
        print("Pudło!")
    if counter == WINCONDITION:
        break
print("CONGRATULATIONS, YOU WON!!!")
