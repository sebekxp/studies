def ins(l, ind):
    for i in range(ind, int(len(l) / ind) * (ind + 1), ind + 1):
        l.insert(i, 0)
    return l


arr = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
arr1 = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
arr2 = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
arr3 = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]

print(ins(arr, 2))
print(ins(arr1, 3))
print(ins(arr2, 4))
print(ins(arr3, 6))
