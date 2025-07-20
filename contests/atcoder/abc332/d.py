from itertools import permutations
rows, cols = map(int, input().split())

grid_a = []
for i in range(rows):
    grid_a.append(list(map(int, input().split())))

grid_b = []
for i in range(rows):
    grid_b.append(list(map(int, input().split())))


ans = float('inf')
def find_count(a: list, b: list):
    count = 0
    index = 0
    while a != b:
        if a[index] == b[index]:
            index += 1

        else:
            dist = a.index(b[index]) - index
            temp = a.pop(index + dist)
            a.insert(index, temp)
            count += dist

        # print(a, b)

    return count


# print(find_count([0, 4, 2, 1, 3], [0, 1, 2, 3, 4]))


for row_perm in permutations([i for i in range(rows)]):
    for col_perm in permutations([i for i in range(cols)]):
        # print(row_perm, col_perm)
        new_grid = [[0 for _ in range(cols)] for _ in range(rows)]
        works = True
        for i in range(rows):
            for j in range(cols):
                new_grid[i][j] = grid_a[row_perm[i]][col_perm[j]]
                if new_grid[i][j] != grid_b[i][j]:
                    works = False
                    break
            
            if not works:
                break
        
        if works:
            ans = min(ans, find_count(list(row_perm), [i for i in range(rows)]) + find_count(list(col_perm), [i for i in range(cols)]))

print(-1 if ans == float('inf') else ans)