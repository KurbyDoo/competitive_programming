n, m = map(int, input().split())
target = list(input())
stamp = input()
cur = ""

q = []
for i in range(n):
    if len(cur) == m:
        cur = cur[1:] + target[i]
    else:
        cur += target[i]

    if cur == stamp:
        q.append(i)

# print(*q)

while len(q) > 0:
    pos = q.pop()
    for i in range(m):
        target[pos - i] = "#"

    for start in range(max(0, pos - m - m + 2), min(n - m + 1, pos + 1)):
        if start == pos - m + 1:
            continue
        works = True
        letter_count = 0
        for i in range(m):
            if target[start + i] != stamp[i] and target[start + i] != "#":
                works = False
                break
            else:
                if target[start + i] != "#":
                    letter_count += 1
        if works and letter_count > 0:
            q.append(start + m - 1)

    # print(*target)

letter_count = 0
for c in target:
    if c != "#":
        letter_count += 1
if letter_count == 0:
    print("Yes")
else:
    print("No")