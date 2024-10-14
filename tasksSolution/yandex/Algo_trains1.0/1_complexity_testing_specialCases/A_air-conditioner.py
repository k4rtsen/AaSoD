t_room, t_cond = input().split()
t_room = int(t_room)
t_cond = int(t_cond)

mode = input()

if (mode == "fan"):
    print(t_room)
elif (mode == "auto"):
    print(t_cond)
elif (mode == "heat"):
    if (t_room >= t_cond):
        print(t_room)
    else:
        print(t_cond)
elif (mode == "freeze"):
    if (t_room <= t_cond):
        print(t_room)
    else:
        print(t_cond)
