n = int(input())
scores = list(map(int, input().split()))
pairs = []
output = [0] * n
for index, item in enumerate(scores):
    pairs.append((item, index))

pairs.sort(reverse=True)
rank = 0
cur = None
last = 0
for a, b in pairs:
    rank += 1
    if a != cur:
        cur = a
        last = rank
    
    output[b] = last

print(*output)
