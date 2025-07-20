ans = 0
for i in range(12):
    s = input()
    ans += len(s) == i + 1
print(ans)