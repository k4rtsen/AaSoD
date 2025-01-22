CODE = '8495'
YES = 'YES'
NO = 'NO'

str = input()
# убрать лишнее
new_num = ''
for ch in str:
    if (ch.isdigit()):
        new_num += ch
# если короткий добавить код
if (len(new_num) == 7):
    new_num = CODE + new_num

nums = []
for i in range(3):
    str = input()
    num = ''
    # remove unnecessary chars
    for val in str:
        if val.isdigit():
            num += val
    nums.append(num)

# comparing
result = []
for val in nums:
    if (len(val) == 7):
        # к меньшему добавляем дефолтный код
        val = CODE + val
    # сравниваем код и номер
    if (val[1:len(val)] == new_num[1:len(val)]):
        result.append(YES)
    else:
        result.append(NO)

for val in result:
    print(val)
