dist = 0
n = int(input())
s = input()
t = input()
for i in range(n):
    if s[i] != t[i]:
        dist += 1

print(dist)