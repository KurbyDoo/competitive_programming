from collections import defaultdict
import sys
input = sys.stdin.readline
graph = defaultdict(list)
n, m = map(int, input().split())
edge_count = [0] * (n + 10)
for i in range(m):
    a, b = map(int, input().split())
    graph[a].append(b)
    graph[b].append(a)

if len(graph[1]) != 1:
    print("NO")

else:
    cur_node = 1
    past = -1
    out = "YES"
    while cur_node != n:
        # print(f"at {cur_node = }")
        if len(graph[cur_node]) > 2:
            out = "NO"
            break

        for i in graph[cur_node]:
            if i != past:
                past = cur_node
                cur_node = i
                break
    
    print(out)
    if out == "YES":
        for i in range(m):
            print(i + 1)
# 6 5
# 1 2
# 2 6
# 3 6
# 3 5
# 3 4