# Author: KurbyDoo
# Creation Date: Jul 19, 2025
# Problem Link: https://dmoj.ca/problem/ccc09s3
# Problem Name: CCC '09 S3 - Degrees Of Separation
# Status: Solved
# Notes:
#     Original creation date unknown
#     
#     
#     
class Matrix():
    matrix = [[], [6], [6], [4, 5, 6, 15], [3, 5, 6], [3, 4, 6], [1, 2, 3, 4, 5, 7], [6, 8], [7, 9], [8, 10, 12], [9, 11], [10, 12], [9, 11, 13], [12, 14, 15], [13], [
        3, 13], [17, 18], [16, 18], [16, 17], [], [], [], [], [], [], [], [], [], [], [], [], [], [], [], [], [], [], [], [], [], [], [], [], [], [], [], [], [], [], [], []]

    def create_friends(self, x, y):
        if y not in self.matrix[x]:
            self.matrix[x].append(y)

        if x not in self.matrix[y]:
            self.matrix[y].append(x)

    def delete_friends(self, x, y):
        if y in self.matrix[x]:
            self.matrix[x].remove(y)

        if x in self.matrix[y]:
            self.matrix[y].remove(x)

    def n_friends(self, x) -> int:
        return len(self.matrix[x])

    def friends_of_friends(self, x) -> int:
        n = []
        for i in self.matrix[x]:
            n.extend(self.matrix[i])

        n = list(set(n))
        n.remove(x)
        for i in self.matrix[x]:
            if i in n:
                n.remove(i)

        return len(n)

    def deg_of_sep(self, x, y):
        depth = self.check(x, y, 1)
        if depth:
            return depth

        else:
            return "Not connected"

    def check(self, item, target, depth, old_checked=[]):
        # print(f"checking {item} at {depth = } {old_checked = }")
        tocheck = self.matrix[item]

        checked = old_checked.copy()
        checked.append(item)
        if target in tocheck:
            # print(f"found at {depth = }")
            return depth

        else:
            depths = []
            for i in tocheck:
                if i not in checked:
                    output = self.check(i, target, depth + 1, checked)
                    if output:
                        depths.append(output)

            if depths:
                return min(depths)


m = Matrix()

sc = " "
while sc != "q":
    sc = input()

    if sc == "i":
        x = int(input())
        y = int(input())
        m.create_friends(x, y)

    elif sc == "d":
        x = int(input())
        y = int(input())
        m.delete_friends(x, y)

    elif sc == "n":
        x = int(input())
        print(m.n_friends(x))

    elif sc == "f":
        x = int(input())
        print(m.friends_of_friends(x))

    elif sc == "s":
        x = int(input())
        y = int(input())
        print(m.deg_of_sep(x, y))
