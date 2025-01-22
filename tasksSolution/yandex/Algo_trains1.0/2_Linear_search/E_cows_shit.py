size = int(input())
arr = list(map(int, input().split()))
        
chemp = max(arr)
start = arr.index(chemp)
vasily = 0
for i in range(start + 1, len(arr) - 1):
    if (arr[i] > arr[i + 1]) and (arr[i]%10 == 5) and (arr[i] > vasily):
        vasily = arr[i]

if vasily == 0:
    print(vasily)
else:
    place = 1
    for val in arr:
        if val > vasily:
            place += 1

    print(place)
    