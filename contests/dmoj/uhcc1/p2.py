k = int(input())
s = input()
overlap = [0] * k
n = int(input())
for _ in range(n):
    to_match = input()
    for i in range(len(to_match), k + 1):
        # print(i, s[i - len(to_match):i])
        if to_match == s[i - len(to_match):i]:
            for j in range(i - len(to_match), i):
                overlap[j] += 1

out = 0
for i in overlap:
    if i >= 2:
        out += 1
print(out)