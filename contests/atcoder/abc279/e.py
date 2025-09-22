n, m = map(int, input().split())
A = list(map(int, input().split()))
B = [i for i in range(1, n + 1)]
pairs = []
for ai in A:
    pairs.append((B[ai - 1], B[ai]))
    B[ai - 1], B[ai] = B[ai], B[ai - 1]

locs = {}
for i in range(n):
    locs[B[i]] = i + 1

for a, b in pairs:
    if a == 1:
        print(locs[b])
    elif b == 1:
        print(locs[a])
    else:
        print(locs[1])
