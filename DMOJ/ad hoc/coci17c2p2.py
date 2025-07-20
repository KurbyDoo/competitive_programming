from collections import defaultdict
k, n = map(int, input().split())
words = defaultdict(list)
idx = defaultdict(int)
for _ in range(k):
    s = input()
    words[s[0]].append(s)

for c in "abcdefghijklmnopqrstuvwxyz":
    words[c].sort()
    idx[c] = 0

for _ in range(n):
    l = input()
    print(words[l][idx[l]])
    idx[l] = (idx[l] + 1) % len(words[l])
