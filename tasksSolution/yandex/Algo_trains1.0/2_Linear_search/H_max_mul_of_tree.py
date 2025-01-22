arr = list(map(int, input().split()))

max1 = max(arr[0], arr[1], arr[2])
max2 = sorted([arr[0], arr[1], arr[2]])[1]
max3 = min(arr[0], arr[1], arr[2])

min1 = min(arr[0], arr[1])
min2 = max(arr[0], arr[1])

if len(arr) > 3:
    for val in arr[3:len(arr)]:
        if val > max1:
            max3 = max2
            max2 = max1
            max1 = val
        elif val > max2:
            max3 = max2
            max2 = val
        elif val > max3:
            max3 = val
    for val in arr[2:len(arr)]:
        if val < min1:
            min2 = min1
            min1 = val
        elif val < min2:
            min2 = val
    a, b = (max2, max3) if max1*max2*max3 > max1*min1*min2 else (min1, min2)
    print(max1, a, b)
else:
    print(max1, max2, max3)
