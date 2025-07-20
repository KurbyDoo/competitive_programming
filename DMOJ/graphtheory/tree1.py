# Author: KurbyDoo
# Creation Date: Jul 19, 2025
# Problem Link: https://dmoj.ca/problem/tree1
# Problem Name: Is it a Tree?
# Status: Solved
# Notes:
#     Original creation date unknown
#     
#     
#     
matrix = [list(map(int, input().split())) for _ in range(4)]

graph = {}

for y in range(len(matrix)):
    for x in range(len(matrix)):
        if matrix[x][y]:
            if graph.get(x, False):
                if y not in graph[x]:
                    graph[x].append(y)

            else:
                graph[x] = [y]

            if graph.get(y, False):
                if x not in graph[y]:
                    graph[y].append(x)

            else:
                graph[y] = [x]

# all_nodes = list(graph.keys())
# checked = []

# stack = [['start', all_nodes[0]]]
# output = "Yes"
# past = "NONE"

# while stack:
#     if stack[0][1] in checked:
#         output = "No"
#         print(f"loop detected")
#         break
#     checked.append(stack[0][1])

#     for i in graph[stack[0][1]]:
#         if i != stack[0][0]:
#             stack.append([stack[0], i])

#     past = stack.pop(0)


# if all_nodes.sort() != checked.sort():
#     output = "No"
#     print(all_nodes, checked)

# if len(all_nodes) == 1:
#     output = "Yes"

# print(output)
# print(f"{graph = }")

class Graph():
    def __init__(self, graph):
        self.graph = graph
        self.checked = []

    def check_length(self):
        return self.graph.get(0, False)

    def check_node(self, parent, node):
        if node in self.checked:
            return True

        else:
            self.checked.append(node)

        toCheck = self.graph[node]
        for i in toCheck:
            if i != parent:
                if self.check_node(node, i):
                    return True

g = Graph(graph=graph)

if not g.check_length():
    print('No')

else:
    if g.check_node('start', 0):
        print("No")

    else:
        print('Yes')