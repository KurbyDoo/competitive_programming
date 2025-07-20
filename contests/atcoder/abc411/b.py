n = int(input())
nums = list(map(int, input().split()))
for i in range(n - 1):
    out = [0]
    for j in range(i, n - 1):
        out.append(out[-1] + nums[j])
    out = out[1:]
    print(*out)