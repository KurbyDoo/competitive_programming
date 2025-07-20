n, k = map(int, input().split())
nums = list(set(list(map(int, input().split()))))
nums.sort(reverse=True)
total = (k * (k + 1)) // 2
while nums and nums[-1] <= k:
    total -= nums.pop()
print(total)
