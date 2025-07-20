import math
t = int(input())

def solve():
    n, l, r = map(int, input().split())
    nums = list(map(int, input().split()))
    sz = r - l + 1
    left = [0] + nums[:(l - 1)]
    right = [0] + nums[r:]
    mid = [0] + nums[(l - 1):r]
    
    left.sort()
    right.sort()
    left = left + [math.inf] * (sz + 1)
    right = right + [math.inf] * (sz + 1)
    mid.sort()
    # print(left, mid, right)
    for i in range(1, len(left)):
        left[i] += left[i - 1]
    for i in range(1, len(right)):
        right[i] += right[i - 1]
    for i in range(1, len(mid)):
        mid[i] += mid[i - 1]
    # print(left, mid, right)
    ans = math.inf
    for i in range(sz + 1):
        ans = min(min(mid[i] + left[sz - i], mid[i] + right[sz - i]), ans)
        # print(ans)
        # print(mid[i] + left[sz - i], mid[i] + right[sz - i])
    print(ans)
        

for _ in range(t):
    solve()