from collections import defaultdict
n = int(input())
nums = list(map(int, input().split()))
sorted_nums = sorted(nums, reverse=True)
thing = defaultdict(int)
total = sum(nums)
cur_num = 0
while sorted_nums:
    if sorted_nums[-1] == cur_num:
        total -= sorted_nums[-1]
        sorted_nums.pop()

    elif sorted_nums[-1] > cur_num:
        thing[cur_num] = total
        cur_num = sorted_nums[-1]

ans = []
for i in nums:
    ans.append(thing[i])

print(*ans)
