# test later
t = int(input())
for _ in range(t):
    n = int(input())
    nums = [0] + list(map(int, input().split()))
    t = [0] * (n + 1)
    f = [0] * (n + 1)
    lies = 0
    ans = 0
    t[0] = 1
    for i in range(1, n + 1):
        f[i] = t[i - 1]
        if nums[i] > i // 2:
            t[i] = 0
            f[i - 1] = 0
            lies += 1

        elif nums[i] != nums[i - 1]:
            if nums[i] != nums[i - 2] + 1: 
                t[i] = 0
                f[i - 1] = 0
                lies += 1
            elif t[i - 1] == 0 and nums[i] == lies:
                t[i] = f[i - 1]

            elif nums[i] != lies + 1:
                t[i] = 0
                f[i - 1] = 0
                lies += 1
            else: 
                t[i] = f[i - 1]
                lies += 1

        else:
            if nums[i] != lies:
                t[i] = 0
                f[i - 1] = 0
                lies += 1

            elif i > 1 and nums[i - 2] != nums[i]: # wrong 0 1 2 2 3 3 4 4 5 5
                t[i] = (f[i - 1] + f[i - 2]) % 998244353
            else:
                t[i] = t[i - 1]

        if t[i] + f[i] == 0:
            break
    # print(*t[1:])
    # print(*f[1:])
    print((t[n] + f[n]) % 998244353)
