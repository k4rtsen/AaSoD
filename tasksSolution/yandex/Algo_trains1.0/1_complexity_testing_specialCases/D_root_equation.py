a = int(input())
b = int(input())
c = int(input())

if c < 0:
    print("NO SOLUTION")
else:
    if a == 0:
        if b == c * c:
            print("MANY SOLUTIONS")
        else:
            print("NO SOLUTION")
    else:
        if ((c * c - b) % a) == 0:
            x = (c * c - b) / a
            print(int(x))
        else:
            print("NO SOLUTION")
