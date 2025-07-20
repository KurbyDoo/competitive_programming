n, q = map(int, input().split())
nums = [i for i in range(1, n + 1)]
offset = 0
for _ in range(q):
    t, *args = map(int, input().split())
    if t == 1: nums[(args[0] + offset + n - 1) % n] = args[1]
    elif t == 2: print(nums[(args[0] + offset + n - 1) % n])
    else: offset += args[0]