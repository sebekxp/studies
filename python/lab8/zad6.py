def iloczyn(l1, l2):
    return sum(x1 * x2 for x1, x2 in zip(l1, l2))


arr1 = [1, 2, 3, 4, 5]
arr2 = [1, 2, 3, 4, 5]
print(iloczyn(arr1, arr2))
