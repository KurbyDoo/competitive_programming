# Author: KurbyDoo
# Creation Date: Jul 19, 2025
# Problem Link: https://dmoj.ca/problem/ratmaze
# Problem Name: Rat In A Maze
# Status: Solved
# Notes:
#     Original creation date unknown
#     
#     
#     
import sys
import timeit
class Graph():
    def __init__(self, inputs):
        self.size = int(inputs.pop(0))
        self.graph = []
        self.checked = [[False for _ in range(self.size)] for _ in range(self.size)]

        for i in range(self.size):
            # self.graph.append(list(map(int, inputs[0].split())))
            # inputs.pop(0)
            self.graph.append([0] * self.size)


    def solve(self):
        to_check = [[0, 0]]
        counter = 0
        while len(to_check) > 0:
            counter += 1
            node = to_check.pop(0)

            x, y = node
            self.checked[x][y] == True

            if node == [self.size - 1, self.size - 1]:
                return "yes"
            
            x, y = node
            n = self.size

            if x + 1 < n and self.graph[y][x + 1] == 0 and not self.checked[x + 1][y]:
                to_check.append([x + 1, y])
                self.checked[x + 1][y] = True

            if x - 1 >= 0 and self.graph[y][x - 1] == 0 and not self.checked[x - 1][y]:
                to_check.append([x - 1, y])
                self.checked[x - 1][y] = True


            if y + 1 < n and self.graph[y + 1][x] == 0 and not self.checked[x][y + 1]:
                to_check.append([x, y + 1])
                self.checked[x][y + 1] = True

            if y - 1 >= 0 and self.graph[y - 1][x] == 0 and not self.checked[x][y - 1]:
                to_check.append([x, y - 1])
                self.checked[x][y - 1] = True

        # for i in self.graph[node]:
        #         if i not in checked:
        #             to_check.append(i)
        #             checked.append(i)

        return "no"


    def solve_v2(self):
        to_check = [[0, 0]]
        checked = set("[0, 0]")
        counter = 0
        while len(to_check) > 0:
            counter += 1
            node = to_check.pop(0)

            x, y = node
            checked.add(f"[{x}, {y}]")

            if node == [self.size - 1, self.size - 1]:
                return "yes"
            
            x, y = node
            n = self.size

            if x + 1 < n and self.graph[y][x + 1] == 0 and f"[{x + 1}, {y}]" not in checked:
                to_check.append([x + 1, y])
                checked.add(f"[{x + 1}, {y}]")

            if x - 1 >= 0 and self.graph[y][x - 1] == 0 and f"[{x - 1}, {y}]" not in checked:
                to_check.append([x - 1, y])
                checked.add(f"[{x - 1}, {y}]")


            if y + 1 < n and self.graph[y + 1][x] == 0 and f"[{x}, {y + 1}]" not in checked:
                to_check.append([x, y + 1])
                checked.add(f"[{x}, {y + 1}]")

            if y - 1 >= 0 and self.graph[y - 1][x] == 0 and f"[{x}, {y - 1}]" not in checked:
                to_check.append([x, y - 1])
                checked.add(f"[{x}, {y - 1}]")

        # for i in self.graph[node]:
        #         if i not in checked:
        #             to_check.append(i)
        #             checked.append(i)

        return "no"

# inputs = sys.stdin.read().split('\n')
with open('test.txt') as f:
    inputs = f.readlines()

print(f"v1:")
start = timeit.default_timer()
graph = Graph(inputs)
print(graph.solve())
print(timeit.default_timer() - start)

print(f"v2")
start = timeit.default_timer()
graph_v2 = Graph(inputs)
print(graph_v2.solve_v2())
print(timeit.default_timer() - start)
