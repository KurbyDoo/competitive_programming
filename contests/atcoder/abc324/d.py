import math
n = int(input())
s = input()
# big = int(math.sqrt(int("".join(sorted(list(s), reverse=True)))))
s = "".join(sorted(list(s)))
# print(s)
count = 0
for i in range(0, int(math.sqrt(10 ** n)) + 1):
    t = "".join(sorted(list(str(i * i))))
    if s == ("0" * (len(s) - len(t))) + t:
        count += 1
        # print(f"{i = }, {t = } {s = }")
        # print(t)
print(count)
