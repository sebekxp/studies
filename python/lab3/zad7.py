def delete(l):
    del l[2::3]
    return [x for x in l if x >= 0]


arr = [0, 1, -5, 8, 14, 9, 6, 2, 5, 16, 15]
arr1 = [0, 1, -5, 8, 14, 9, 6, 2, 5, 16, 15]

print(delete(arr))
