from collections import defaultdict
n = int(input())
coords = []
x = list(map(int, input().split()))
coords.extend(x)
p = list(map(int, input().split()))
q = int(input())
queries = []
for _ in range(q):
  a, b = map(int, input().split())
  coords.append(a)
  coords.append(b)
  queries.append((a, b))

coords = sorted(set(coords))
mapping = defaultdict(int)
for index, item in enumerate(coords):
  mapping[item] = index

size = len(coords)
psa = [0] * (size + 2)
for a, b in zip(x, p):
  psa[mapping[a] + 1] += b

# print(*coords)
# print(*psa)

for i in range(size):
  psa[i + 1] += psa[i]

for a, b in queries:
  print(psa[mapping[b] + 1] - psa[mapping[a]])