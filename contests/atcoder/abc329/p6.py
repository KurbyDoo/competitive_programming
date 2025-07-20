import sys
input = sys.stdin.readline
n, q = map(int, input().split())
boxes = [set()] * (n + 1)
balls = list(map(int, input().split()))
for b in range(n):
    boxes[b + 1] = set([balls[b]])

for i in range(q):
    a, b = map(int, input().split())

    if len(boxes[a]) > len(boxes[b]):
        boxes[a], boxes[b] = boxes[b], boxes[a]

    for ball in boxes[a]:
        boxes[b].add(ball)
    boxes[a] = set()
    print(len(boxes[b]))