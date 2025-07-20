from collections import defaultdict
n, m = map(int, input().split())
a = list(map(int, input().split()))
b = list(map(int, input().split()))
inA = defaultdict(bool)
c = a + b
c.sort()
out = "No"
for thing in a:
    inA[thing] = True

for i in range(n + m - 1):
    if inA[c[i]] and inA[c[i + 1]]:
        out = "Yes"

print(out)