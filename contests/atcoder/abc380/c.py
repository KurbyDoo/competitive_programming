n, k = map(int, input().split())
s = input()
ones = 0
last = False
stk = []
for i in range(n):
    if not stk or stk[-1][0] != s[i]:
        stk.append([s[i], 1])

    else:
        stk[-1][1] += 1
# print(*stk)

for i in range(len(stk)):
    a, b = stk[i]
    if a == '1': ones += 1
    if ones == k:
        stk[i - 2][1] += b
        stk.pop(i)
        break
    
out = []
for a, b in stk:
    out.append(a * b)
print("".join(out))