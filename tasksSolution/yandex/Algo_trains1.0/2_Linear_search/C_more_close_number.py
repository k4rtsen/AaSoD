len = int(input())
arr = list(map(int, input().split()))
num = int(input())

def FindCloserNum(arr, num) -> int:
    dif = abs(arr[0] - num)
    index = 0
    for i, val in enumerate(arr):
        if (abs(num - val) < dif):
            dif = abs(num - val)
            index = i
    return arr[index]

print(FindCloserNum(arr, num))