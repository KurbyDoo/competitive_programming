from collections import defaultdict
freq = defaultdict(int)
n = int(input())
for _ in range(10 * n):
    nums = list(map(int, input().split()))
    for i in nums:
        freq[i] += 1

out = []
for i in freq:
    if freq[i] > 2 * n:
        out.append(i)
out.sort()
if out:
    print(*out)

else:
    print(-1)