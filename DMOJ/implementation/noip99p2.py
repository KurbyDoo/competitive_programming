import sys

base = int(input())
o = input()
num = o
convert = list("0123456789ABCDEFG")
num = list(o)


def check(number):
    works = True
    for i in range((len(number) + 1) // 2):
        if number[i] != number[-i - 1]:
            # print(# f"no work {number} {i, -i - 1} {number[i], number[-i - 1]}")
            works = False
            break

    return works


for i in range(30):
    forwards = num.copy()
    backwards = num[::-1].copy()

    if base == 16:
        forwards = []
        for n in num:
            forwards.append(convert.index(str(n)))

        backwards = forwards[::-1]
    # print(forwards)
    # print(backwards)
    new = [0 for _ in range(len(num) + 2)]

    for j in range(len(num)):
        # print(int(forwards[j]) + int(backwards[j]))
        total = new[-j - 1] + int(forwards[j]) + int(backwards[j])
        new[-j - 1] = (total) % base
        new[-j - 2] = (total) // base

        # print(new)

    j = 0
    while new[j] == 0:
        new.pop(0)

    if base == 16:
        a = []
        for n in new:
            a.append(convert[n])

        new = a
    newNumber = "".join(list(map(str, new)))
    # print(*new)
    if check(newNumber):
        # print(base, o)
        print(f"STEP={i + 1}")
        sys.exit()

    num = new

print("Impossible!")
