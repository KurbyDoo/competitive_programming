t = int(input())
for _ in range(t):
    n = int(input())
    nums = list(map(int, input().split()))
    even, odd = 0, 0
    for a in nums:
        if a % 2:
            odd += 1
        else:
            even += 1

    s = 0
    odd
    print(odd + (1 if even > 0 else -1))