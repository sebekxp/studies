import random


def sumNeighbors(list):
    temp = [(list[i - 1] + list[i] + list[i + 1]) / 3 for i in range(1, len(list) - 1)]
    temp.insert(0, list[0])
    temp.append(list[len(list) - 1])
    return temp


arr = [3, 1, 2, 0, 4]
arr1 = [4, 8, 7, 2, 1, 9]
arr2 = [random.randint(1, 20) for x in range(20)]

print(sumNeighbors(arr))
print(sumNeighbors(arr1))
print(sumNeighbors(arr2))
