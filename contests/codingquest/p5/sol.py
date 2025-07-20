from collections import defaultdict
import math
graph = defaultdict(lambda: defaultdict(int))
edges = "base    cg96    hx27    ik04    qx43    dc94    ap98    ux20    li84    rt50    el82    rd48    sf80    mg52    rc82    eu85    hr27    bi41    sh80    af18    vp88    km46    em44    pd69    ts86".split()
with open("contests\codingquest\p5\input.txt") as f:
    total = 0
    lines = f.readlines()
    # for line in lines[1:5]:
    for line in lines[1:len(edges) + 1]:
        things = line.split()
        # print(things[0])

        for i in range(len(things) - 1):
            # print(f"{things[0]} - > {edges[i]} {things[i + 1]}")
            graph[things[0]][edges[i]] = int(things[i + 1])

    for line in lines[len(edges) + 2:]:
    # for line in lines[6:]:
        a, b = line.split(":")
        order = list(map(lambda a: a.strip(), b.split("->")))
        print(*order)
        past = "base"
        for i in order[1:]:
            print(graph[past][i], past, i)
            total += graph[past][i]
            past = i

    print(total)


        
            


