n, k, m = map(int, input().split())

count = 0
while n >= k >= m:
    zag = n // k
    n = n % k
    for i in range(zag):
        count += k // m
        n += k % m

print(count)
