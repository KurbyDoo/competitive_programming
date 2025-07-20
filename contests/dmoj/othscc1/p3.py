n, d = map(int, input().split())
bombs = list(map(int, input().split()))

past = float('inf')
chain = 0
count = 0
max_chain = 0
for i in range(n):
    if abs(bombs[i] - past) <= d:
        chain += 1
        max_chain = max(chain, max_chain)

    else:
        count += 1
        chain = 1

    past = bombs[i]

print(count)
print(max_chain)
