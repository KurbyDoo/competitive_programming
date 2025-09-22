h, w = map(int, input().split())
S = [input() for _ in range(h)]
O = [input() for _ in range(h)]

c1 = []
for i in range(w):
    col = []
    for j in range(h):
        col.append(S[j][i])
    c1.append("".join(col))
c2 = []
for i in range(w):
    col = []
    for j in range(h):
        col.append(O[j][i])
    c2.append("".join(col))

print("Yes" if sorted(c1) == sorted(c2) else "No")
# print(sorted(c1), sorted(c2))