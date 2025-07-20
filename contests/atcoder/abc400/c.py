import math

"""
2 (1, 1)
4 (2, 1)
8 (3, 1)
16 (4, 1)
18 (1, 3)
32 (5, 1)
36 (2, 3)
50 (1, 5)
"""

def solve(n):
    # n = int(input())

    a_max = int(math.log2(n) + 10)
    ans = 0
    for a in range(1, a_max + 1):
        # b^2 = n / (2^a)
        # 2log_2(b) = log_2(n) - a
        # b = int(2 ** ((math.log2(n) - a) / 2) + 1)
        b = int(pow(n / (2 ** a), 0.5) + 10)
        while (1 << a) * b * b > n:
            # assert (1 << a) * b * b > n, f"Failed for a={a}, b={b}, n={n}"
            b -= 1
        # print(f"{a=} {b=}")
        ans += (b + 1) // 2
    return ans

print(solve(int(input())))
# nums = set()
# for a in range(1, 60):
#     for b in range(1, 10000):
#         nums.add((1 << a) * b * b)

# nums_sorted = sorted(nums, reverse=True)
# # N = int(input())
# print(nums_sorted)
# next_item = nums_sorted.pop()
# count = 1
# for i in range(2, 600000):
#     if nums_sorted and nums_sorted[-1] <= i:
#         next_item = nums_sorted.pop()
#         count += 1
    
#     val = solve(i)
#     assert val == count, f"Failed for i={i}, expected {count}, got {val}"
#     print(f"i={i}, count={count}, val={val}")

