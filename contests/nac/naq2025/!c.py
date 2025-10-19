n, k = map(int, input().split())
unique = set()
for i in range(n):
    unique.add(int(input()))

print(min(len(unique), k))
## SUBMITTED