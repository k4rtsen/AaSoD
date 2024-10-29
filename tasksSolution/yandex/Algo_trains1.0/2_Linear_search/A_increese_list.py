def isIncreese(list : list) -> str:
    cur_elem = list[0]
    for i in range(1, len(list)):
        if cur_elem >= list[i]:
            return "NO"
        else:
            cur_elem = list[i]
    return "YES"

arr = list(map(int, input().split()))
print(isIncreese(arr))
