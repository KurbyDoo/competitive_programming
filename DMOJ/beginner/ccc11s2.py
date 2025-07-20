ans = []
n = int(input())

for _ in range(n):
    ans.append(input())


count = 0
for i in range(n):
    if input() == ans[i]: count += 1

print(count)