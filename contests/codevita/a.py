from collections import defaultdict
from queue import Queue
n = int(input())
graph = defaultdict(list)
cost = defaultdict(int)
things = Queue()
for i in range(n):
    v, e = input().split("=")
    for item in e.split('+'):
        things.put(item)
    things.put(v)
    graph[v].append(item)
    graph[v].add(b)

while not things.empty():
    cur = things.get()

