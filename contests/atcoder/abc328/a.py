n, x = map(int, input().split())
nums = list(map(int, input().split()))
total = 0
for i in nums:
    if i <= x:
        total += i

print(total)
