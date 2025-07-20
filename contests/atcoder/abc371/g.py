from collections import defaultdict
n = int(input())
p = list(map(int, input().split()))
a = list(map(int, input().split()))
checked = [False] * n
smallest_ops = [0] * n
smallest_val = [i for i in a]

appeared = defaultdict(bool)

for i in range(1, n + 1):
    if checked[i - 1]: continue
    cur_pos = i
    operations = 0
    checked[i - 1] = True
    for _ in range(n):
        cur_pos = p[cur_pos - 1]
        if cur_pos == i:
            break
        operations += 1
        if a[cur_pos - 1] < smallest_val[i - 1]:
            smallest_ops[i - 1] = operations
            smallest_val[i - 1] = a[cur_pos - 1]

        checked[cur_pos - 1] = True

out = [0] * n
added = [False] * n
for i in range(n):
    start_pos = i + 1
    end_pos = i + 1
    if added[start_pos - 1]: continue
    for j in range(smallest_ops[i]):
      end_pos = p[end_pos - 1]

    for j in range(n):
        out[start_pos - 1] = a[end_pos - 1]
        added[start_pos - 1] = True
        start_pos = p[start_pos - 1]
        end_pos = p[end_pos - 1]
        if start_pos == i + 1: break
    
    # print(*out)

# print(smallest_ops, smallest_val)
print(*out)
