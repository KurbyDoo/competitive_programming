from collections import deque

dq = deque()
n, m = map(int, input().split())
dq.extend(map(int, input().split()))

front = dq.popleft() - 1
for i in range(n):
    print(front - i)
    if front == i and i != n - 1:
        front = dq.popleft() - 1