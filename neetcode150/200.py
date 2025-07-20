class Solution:
    def numIslands(self, grid: list[list[str]]) -> int:
        self.graph = grid
        self.r = len(self.graph)
        self.c = len(self.graph[0])
        self.visited = [[False for _ in range(self.r)] for _ in range(self.c)]

        return self.find()

    # look for a unchecked bacteria
    def find(self) -> None:
        num = 0
        # starting top left moving right then down
        for y in range(self.r):
            for x in range(self.c):
                if not self.visited[x][y]:
                    self.visited[x][y] = True
                    if self.graph[y][x] != "0":
                        self.solve(x, y)
                        num += 1

        return num

    # Find colony size
    def solve(self, start_x, start_y) -> None:
        to_check = [(start_x, start_y)]

        # Check first tile in to_check
        while to_check:
            x, y = to_check.pop()

            # add all adjacent tiles to to_check
            if 0 <= x + 1 < self.c and not self.visited[x + 1][y] and self.graph[y][x + 1] != "0":
                to_check.append((x + 1, y))
                self.visited[x + 1][y] = True

            if 0 <= x - 1 < self.c and not self.visited[x - 1][y] and self.graph[y][x - 1] != "0":
                to_check.append((x - 1, y))
                self.visited[x - 1][y] = True

            if 0 <= y + 1 < self.r and not self.visited[x][y + 1] and self.graph[y + 1][x] != "0":
                to_check.append((x, y + 1))
                self.visited[x][y + 1] = True

            if 0 <= y - 1 < self.r and not self.visited[x][y - 1] and self.graph[y - 1][x] != "0":
                to_check.append((x, y - 1))
                self.visited[x][y - 1] = True

        # prints the starting bacteria and the colony size
