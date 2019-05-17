def getList(list):
    print("Min value: ", min(list))
    print("Max value: ", max(list))

    sum = 0
    for i in list:
        sum += i

    print("Average value: ", sum / len(list))


arr = [1, 2, 3, 4, 5]
arr1 = [1, 2, 3]
arr2 = [5, 5, 5, 5, 5]

getList(arr)
getList(arr1)
getList(arr2)
