import math

def min_rooms(rooms, k2, k2_cell):
    min_rooms = rooms
    # поиск минимального количества квартир в одной ячейке
    for i in range(rooms, 0, -1):
            if math.ceil(k2 / i) == k2_cell:
                min_rooms = i
    return min_rooms

def max_rooms(rooms, k2, k2_cell):
    max_rooms = rooms
    # поиск максимального количества квартир в одной ячейке
    while (math.ceil(k2 / (max_rooms + 1)) == k2_cell):
        max_rooms += 1
    return max_rooms

# k1 - номер
# m  - этажей в дома
# k2 - вторая квартира
# p2 - подъезд второй квартиры
# n2 - этаж второй квартиры

def amb(k1, m, k2, p2, n2):
    # самая первая квартира
    if k1 == 1:
        return 1, 1
    # если у второй квартиры больше этажей, чем дано
    if (n2 > m):
        return -1, -1

    k2_cell = m * p2 - (m - n2)  # в какой ячейке находится вторая кв
    # если ячейка больше номера кв, значит где-то есть пустая ячейка, что есть некорректный ввод
    if (k2_cell > k2):
        return -1, -1
    rooms = math.ceil(k2/k2_cell)  # квартир на одной площадке

    # обратный расчет введеных данных для подтверждения корректности ввода
    # некорректные данные подъезда и\или этажа, если номер кв2 не входит в диапазон квартир по данной ячейке
    s = (k2_cell - 1) * rooms
    e = k2_cell * rooms
    if not(s < k2 and k2 <= e):
        return -1, -1
    k1_cell = math.ceil(k1/rooms)  # в какой ячейке первая кв
    p1 = math.ceil(k1_cell/m)  # подъезд первой квартиры
    n1 = k1_cell - m * (p1 - 1)  # этаж первой кв

    # min_room = rooms
    # max_room = rooms

    # если вторая кв находится в первой ячейке, то мы не сможем выяснить сколько квартир на одном этаже
    if (p2 == n2 == 1):
        # достоверно знаем лишь на каком этаже будет квартира, остальное не известно
        if m == 1:
            return 0, 1
        elif k2 == 1:
            return 0, 0
        # первая квартира получает те же данные
        elif k2 > k1:
            return p2, n2
        elif p1 == 1:
            return 1, 0
        
    min_room = min_rooms(rooms, k2, k2_cell)
    max_room = max_rooms(rooms, k2, k2_cell)

    # проверка на неоднозначность входных данных
    for i in range(min_room, max_room + 1):
        temp_cell = math.ceil(k1/i)
        temp_p1 = math.ceil(temp_cell/m)
        temp_n1 = temp_cell - m * (temp_p1 - 1)
        if temp_p1 != p1:
            p1 = 0
        if temp_n1 != n1:
            n1 = 0
    
    return p1, n1

k1, m, k2, p2, n2 = map(int, input().split())
p1, n1 = amb(k1, m, k2, p2, n2)
print(p1, n1)
