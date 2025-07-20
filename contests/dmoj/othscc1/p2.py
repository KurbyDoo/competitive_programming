n = int(input())
things = []
for i in range(n):
    things.append(int(input()))

things.sort()
things.pop()
print(sum(things) // len(things))