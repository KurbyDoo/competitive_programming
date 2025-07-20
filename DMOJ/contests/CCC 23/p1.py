n = int(input())
row1 = [0] + list(map(int, input().split())) + [0]
row2 = [0] + list(map(int, input().split())) + [0]

nEdges = 0

for i in range(1, n + 1):
    if row1[i]:
        if not row1[i + 1]:
            nEdges += 1

        if not row1[i - 1]:
            nEdges += 1

    if row2[i]:
        if not row2[i + 1]:
            nEdges += 1

        if not row2[i - 1]:
            nEdges += 1

    if i % 2 == 1:
        if (row1[i] or row2[i]) and not (row1[i] and row2[i]):
            nEdges += 1

    else:
        if row1[i]:
            nEdges += 1

        if row2[i]:
            nEdges += 1


# 7
# 0 0 1 1 0 1 0
# 0 0 1 0 1 0 0

# 5
# 1 0 1 0 1
# 0 0 0 0 0 

print(nEdges)