import sys
input = sys.stdin.readline

rows, cols = map(int, input().split())

array = [[0 for _ in range(rows)] for _ in range(cols)]
array[0][0] = 1

k = int(input())
for _ in range(k):
    r, c = map(int, input().split())
    array[c - 1][r - 1] = -1

# print(array)
for x in range(cols):
    for y in range(rows):
        # print(f"at {x, y}")
        if array[x][y] == -1:
            continue

        if x + 1 < cols and array[x + 1][y] != -1:
            array[x + 1][y] += array[x][y]

        if y + 1 < rows and array[x][y + 1] != -1:
            array[x][y + 1] += array[x][y]

                    
# print(array)
print(array[-1][-1])