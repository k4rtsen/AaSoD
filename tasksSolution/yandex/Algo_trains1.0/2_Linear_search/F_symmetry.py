count = int(input())
arr = list(map(int, input().split()))
r_arr = list(reversed(arr))
m = 0

for i in range(count):
    # print(arr[i:count])
    # print(r_arr[:count - i - 1])
    if arr[i:count] == r_arr[:count - i]:
        m = i
        break

print(m)
print(' '.join(map(str, reversed(arr[:m]))))
