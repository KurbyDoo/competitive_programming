import math
import heapq
n = int(input())
value = list(map(int, input().split()))
index = [i for i in range(n)] 
lft = [i for i in range(n)]
rght = [i for i in range(n)]
heap = []

def find(a):
    if index[a] == a: return a
    index[a] = find(index[a])
    return index[a]

def join(a, b, force = False):
    a = find(a)
    b = find(b)
    if a != b and (value[a] == value[b] or force):
        index[a] = b
        lft[b] = min(lft[b], lft[a])
        rght[b] = max(rght[b], rght[a])
        if not force:
            value[b] = value[b] * 2
        return True
    return False

for i, v in enumerate(value):
    heapq.heappush(heap, (v, i))

while len(heap) > 1:
    item, idx = heapq.heappop(heap)
    idx = find(idx)
    if value[idx] != item: continue
    if lft[idx] > 0 and join(lft[idx] - 1, idx):
        heapq.heappush(heap, (item * 2, idx))
        continue
    if rght[idx] < n - 1 and join(rght[idx] + 1, idx):
        heapq.heappush(heap, (item * 2, idx))
        continue
    if lft[idx] > 0: join(idx, lft[idx] - 1, True)
    elif lft[idx] < n - 1: join(idx, lft[idx] + 1, True)

# print(value)
# print(index)
print(max(value))