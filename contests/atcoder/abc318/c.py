n, d, p = map(int, input().split())
fares = list(map(int, input().split()))

fares.sort()

cost = 0
while len(fares) >= d:
    if sum(fares[-d:]) < p: break
    for i in range(d):
        fares.pop()
    cost += p

if len(fares) < d and sum(fares) >= p: cost += p
else: cost += sum(fares)
print(cost)