n = int(input())
people = []
ans = 0
for _ in range(n):
    people.append(int(input()))

for i in range(n // 2):
    if people[i] == people[i + n // 2]:
        ans += 2

print(ans)
