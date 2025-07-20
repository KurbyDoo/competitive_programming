n = int(input())
ans = 0
for i in range(n):
    a = int(input())
    ans += 1 if a % 2 == 1 else 0
print(ans)
