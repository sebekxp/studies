def blur(l, k):
    temp = [((l[i - 1] * k[0]) + (l[i] * k[1]) + (l[i + 1] * k[2])) / 3 for i in range(1, len(l) - 1)]
    temp.insert(0, l[0])
    temp.append(l[len(l) - 1])
    return temp


print(blur([3, 1, 2, 0, 4], (1, 1, 1)))
print(blur([3, 1, 2, 0, 4], (2, -1, 2)))
