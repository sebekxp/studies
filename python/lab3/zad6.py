def select(list):
    list.sort()
    print(list)
    return list[0:3] + list[-3:]


arr = [0, 1, -5, 8, 14, 9, 6, 2, 5, 16, 15]
print(select(arr))

