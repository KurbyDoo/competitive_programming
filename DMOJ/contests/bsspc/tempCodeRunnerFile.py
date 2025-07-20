import sys
sys.setrecursionlimit(100000)

a = int(input())
n = input().split()
d = {}

def generate(nums):
    if d.get(" ".join(nums), False): return
    d[" ".join(nums)] = True
    # print(nums)
    for i in range(len(nums)):
        if int(nums[i])%2 == 0:
            generate(nums[:i] + [str(int(nums[i])//2), str(int(nums[i])//2)] + nums[i + 1:])

generate(n)

count = 0
for k in d.keys():
    # print(k)
    count += 1

print(count%1000000007)
