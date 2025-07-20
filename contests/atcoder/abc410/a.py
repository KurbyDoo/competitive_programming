n = int(input())
a = list(map(int, input().split()))
k = int(input())
ans = 0
for b in a:
    if k <= b:
        ans += 1

print(ans)
