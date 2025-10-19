n = int(input())
bonus = list(map(int, input().split()))
solvable = list(map(int, input().split()))
solvable.sort()
total = 0
ans = 0
for i in range(n):
    total += solvable.pop()
    ans = max(ans, (total + bonus[i]) / n)
print(f"{ans:.9f}")
