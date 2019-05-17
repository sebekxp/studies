def copyList(list):
    return [x for x in list]


arr = [1, 2, 3, 4, 5]
a = copyList(arr)
arr[0] = 80

print(arr)
print(a)
