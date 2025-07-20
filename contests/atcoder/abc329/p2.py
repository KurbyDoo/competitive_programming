n = int(input())
nums = list(map(int, input().split()))
nums = sorted(list(set(nums)))
print(nums[-2])