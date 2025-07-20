# CCC '06 J4 - It's tough being a teen!
from collections import defaultdict
import sys
input = sys.stdin.readline

graph = defaultdict(list)
graph[1].append(7)
graph[1].append(4)
graph[2].append(1)
graph[3].append(4)
graph[3].append(5)

count = [9999, 1, 0, 0, 2, 1, 0, 1]

while True:
    a = int(input())
    b = int(input())
    if not (a or b):
        break

    graph[a].append(b)
    count[b] += 1

order = []
for _ in range(7):
    for i, item in enumerate(count):
        if item != 0:
            if i == 7:
                print("Cannot complete these tasks. Going to bed.")
                sys.exit()

            continue

        order.append(str(i))
        count[i] = -1
        for n in graph[i]:
            count[n] -= 1

        break


print(" ".join(order))
