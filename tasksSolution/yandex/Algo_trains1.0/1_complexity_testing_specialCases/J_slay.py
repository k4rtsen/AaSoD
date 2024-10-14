a = int(input())
b = int(input())
c = int(input())
d = int(input())
e = int(input())
f = int(input())

det = a*d - b*c
# case 1 - y = kx + b
if (c != 0 and d != 0 and f != 0 and a/c == b/d == e/f):
    k1 = -a/b
    p1 = e/b
    k2 = -c/d
    p2 = f/d
    if (k1 == k2 and p1 == p2):
        print(1, k1, p1)
    else:
        print("Error case 1!")
elif (a == 0 and c == 0 ): # case 4 - y = y0, x = any
    y1 = e/b
    y2 = f/d
    if y1 == y2:
        print(4, y1)
    else:
        print("Error case 4!")
elif (b == 0 and d == 0): # case 3 - x = x0, y = any
    x1 = e/a
    x2 = f/c
    if x1 == x2:
        print(3, x1)
    else:
        print("Error case 3!")
# case 0 - not solution
elif (det == 0):
    if (e != f):
        print(0) # прямые параллельны
    # and case 5 - a lot of solutions
    else:
        print(5) # прямые совпадают
else: # case 2 - only solution x, y (by method of Kramer)
    det_x = e*d - b*f
    det_y = a*f - e*c
    x = det_x/det
    y = det_y/det
    print(2, x, y)
