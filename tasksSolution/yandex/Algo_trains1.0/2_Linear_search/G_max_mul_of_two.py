# def max_mul(a, b, c, d):
#     return (a, b) if a * b > c * d else (c, d)

arr = list(map(int, input().split()))
# arr.sort()
# max1, max2 = max_mul(arr[0], arr[1], arr[len(arr) - 2], arr[len(arr) - 1])
# print(max1, max2)

max1 = max(arr[0], arr[1])
max2 = min(arr[0], arr[1])
min1 = min(arr[0], arr[1])
min2 = max(arr[0], arr[1])

if len(arr) > 2:
    for val in arr:
        if val > max1:
            max2 = max1
            max1 = val
        elif val > max2:
            max2 = val

        if val < min2:
            min1 = min2
            min2 = val
        elif val < min1:
            min1 = val

a, b = (max1, max2) if max1*max2 >= min1*min2 else (min1, min2)
print(b, a)
