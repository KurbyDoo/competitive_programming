from collections import defaultdict
n, m = map(int, input().split())
nums = list(map(int, input().split()))

ans = 0
modded = [0] + nums + nums
count = defaultdict(int)
for i in range(1, n * 2 + 1):
  modded[i] += modded[i - 1]
  modded[i] %= m

left = n - 1
right = n * 2 - 2
for i in range(right, left, -1):
  count[modded[i]] += 1

for i in range(left + 1):
  ans += count[modded[left - i]]
  count[modded[left - i]] += 1
  count[modded[right - i]] -= 1
print(ans)

