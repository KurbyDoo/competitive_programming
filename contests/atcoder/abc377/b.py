rows = [0] * 8
cols = [0] * 8
for i in range(8):
    s = input()
    if "#" in s:
        rows[i] = 1
    for j in range(8):
        if s[j] == "#":
            cols[j] = 1
ans = 0
for i in range(8):
    for j in range(8):
        if not rows[i] and not cols[j]:
            ans += 1
print(ans)