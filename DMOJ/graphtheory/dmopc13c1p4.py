# Author: KurbyDoo
# Creation Date: Jul 19, 2025
# Problem Link: https://dmoj.ca/problem/dmopc13c1p4
# Status: Solved
# Notes:
#     Original creation date unknown
#     
#     
#     
import sys
import timeit
class Graph():
    def __init__(self):
        # self.inputs = sys.stdin.read().split("\n")
        with open("test.txt") as f:
            self.inputs = f.readlines()

        n_tests = int(self.inputs.pop(0))
        for _ in range(n_tests):
            self.set_graph(list(map(int, self.inputs.pop(0).split())))

    def set_graph(self, dim):
        w, h = dim
        graph = []
        for i in range(h):
            row = list(self.inputs.pop(0))
            if "C" in row:
                c_location = (row.index("C"), i)

            if "W" in row:
                w_location = (row.index("W"), i)

            graph.append(row)

        print(self.solve(graph, w, h, c_location, w_location))

    def solve(self, graph, w, h, c_location, w_location):
        checked = [[False for _ in range(h)] for _ in range(w)]
        c_x, c_y = c_location
        w_x, w_y = w_location
        to_check = [[c_x, c_y, 0]]
        count = 0
        while len(to_check) > 0:
            node = list(map(int, to_check.pop(0)))

            x, y, count = node
            checked[x][y] == True

            # print(f"checking {x, y}")

            if node[0:2] == [w_x, w_y]:
                return count

            if count < 59:
                if x + 1 < w and graph[y][x + 1] in ["O", "W"] and not checked[x + 1][y]:
                    to_check.append([x + 1, y, count + 1])
                    checked[x + 1][y] = True

                if x - 1 >= 0 and graph[y][x - 1] in ["O", "W"] and not checked[x - 1][y]:
                    to_check.append([x - 1, y, count + 1])
                    checked[x - 1][y] = True

                if y + 1 < h and graph[y + 1][x] in ["O", "W"] and not checked[x][y + 1]:
                    to_check.append([x, y + 1, count + 1])
                    checked[x][y + 1] = True

                if y - 1 >= 0 and graph[y - 1][x] in ["O", "W"] and not checked[x][y - 1]:
                    to_check.append([x, y - 1, count + 1])
                    checked[x][y - 1] = True

        return "#notworth"

if __name__ == "__main__":
    graph = Graph()
