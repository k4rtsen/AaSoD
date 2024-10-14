a1, b1, a2, b2 = map(int, input().split())
s = 10000000

h, w = 0, 0
if ((a1 + a2) * max(b1, b2) < s):
    s = (a1 + a2) * max(b1, b2)
    h = a1 + a2
    w = max(b1, b2)

if ((a1 + b2) * max(a2, b1) < s):
    s = (a1 + b2) * max(a2, b1)
    h = a1 + b2
    w = max(b1, a2)

if ((b1 + b2) * max(a1, a2) < s):
    s = (b1 + b2) * max(a1, a2)
    h = b1 + b2
    w = max(a1, a2)

if ((b1 + a2) * max(a1, b2) < s):
    s = (b1 + a2) * max(a1, b2)
    h = b1 + a2
    w = max(a1, b2)

print(h, w)
