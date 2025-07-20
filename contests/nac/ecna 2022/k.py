from collections import defaultdict
s1 = input()
s2 = input()
c1 = s1.replace(" ", "")
c2 = s2.replace(" ", "")
# print(c1, c2)
tree1 = [""]
tree2 = [""]
for c in c1:
    if c in "()":
        if (tree1[-1] == ""): tree1[-1] = c
        else: tree1.append(c)
        tree1.append("")
    else:
        tree1[-1] = tree1[-1] + c
for c in c2:
    if c in "()":
        if tree2[-1] == "": tree2[-1] = c
        else: tree2.append(c)
        tree2.append("")
    else:
        tree2[-1] = tree2[-1] + c

# print(*tree1)
# print(*tree2)
graph1 = defaultdict(list)
past1 = [tree1[0]]
for i in range(1, len(tree1)):
    cur_val = tree1[i]
    # print(f"at {cur_val} {past1}")
    if cur_val == "(": pass
    elif cur_val == ")": past1.pop()
    else:
        graph1[past1[-1]].append(cur_val)
        graph1[cur_val].append(past1[-1])
        past1.append(cur_val)
for k in graph1:
    graph1[k].sort()
graph2 = defaultdict(list)
past2 = [tree2[0]]
for i in range(1, len(tree2)):
    cur_val = tree2[i]
    # print(f"at {cur_val} {past2}")
    if cur_val == "(": pass
    elif cur_val == ")": past2.pop()
    else:
        graph2[past2[-1]].append(cur_val)
        graph2[cur_val].append(past2[-1])
        past2.append(cur_val)
for k in graph2:
    graph2[k].sort()
order1 = []
order2 = []
def dfs1(node, past):
    global order1
    order1.append(node)
    for e in graph1[node]:
        if e == past: continue
        dfs1(e, node)
        order1.append(node)
    order1.append(node)
def dfs2(node, past):
    global order2
    order2.append(node)
    for e in graph2[node]:
        if e == past: continue
        dfs2(e, node)
        order2.append(node)
    order2.append(node)
dfs1(past1[0], -1)
dfs2(past2[0], -1)
# print(order1)
# print(order2)
print("Yes" if order1 == order2 else "No")




