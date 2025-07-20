n = int(input())
start_grid = [input() for _ in range(n)]
end_grid = [input() for _ in range(n)]

ans = n * n
d1 = d2 = d3 = d4 = 0
for r in range(n):
    for c in range(n):
        if start_grid[r][c] != end_grid[r][c]:
            d1 += 1

        if start_grid[c][-r - 1] != end_grid[r][c]:
            d2 += 1

        if start_grid[-r - 1][-c - 1] != end_grid[r][c]:
            d3 += 1

        if start_grid[-c - 1][r] != end_grid[r][c]:
            d4 += 1 

print(min(d1, d2 + 3, d3 + 2, d4 + 1))

# print(f"{d1 = } {d2 = } {d3 = } {d4 = }")