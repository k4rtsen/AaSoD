# intervals
a = int(input())
b = int(input())
# trains count
n = int(input())
m = int(input())
# time for 1st platform
min1 = a * (n - 1) + n
max1 = a * (n + 1) + n
# time for 2nd platform
min2 = b * (m - 1) + m
max2 = b * (m + 1) + m
# results
i_min = max(min1, min2)
i_max = min(max1, max2)
if (i_min > i_max):
    print(-1)
else:
    print(i_min, i_max)
