from collections import defaultdict
t = int(input())



for _ in range(t):
    n = int(input())
    graph = defaultdict(list)
    good = [False] * (n + 1)
    sz = [0] * (n + 1)

    
    def dfs(node, past):
        size = 0
        for e in graph[node]:
            if e == past: continue
            res = dfs(e, node) + 1
            if size == 0: size = res
            elif res != size or not good[e]:
                good[node] = False
                return
        sz[node] = size
    
    for i in range(n - 1):
        a, b = map(int, input().split())
        graph[a].append(b)
        graph[b].append(a)

    ans = 0
    l = 0
    count = defaultdict(int)
    for i in graph[1]:
        if good[i]: count[sz[i]] += 1

    print("ans", len(gra))

    

    