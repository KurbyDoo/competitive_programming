from collections import defaultdict
n, t = map(int, input().split())
scores = [0] * (n + 1)
count = defaultdict(int)
count[0] = n
unique = set([0])

for _ in range(t):
  a, b = map(int, input().split())
  count[scores[a]] -= 1

  if count[scores[a]] == 0:
    unique.remove(scores[a])

  scores[a] += b
  if count[scores[a]] == 0:
    unique.add(scores[a])
  count[scores[a]] += 1

  print(len(unique))