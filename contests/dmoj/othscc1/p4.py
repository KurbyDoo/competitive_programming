n, s, t = map(int, input().split())
robots = list(map(int, input().split()))
psa = [0] * (n + 1)
for i in range(n):
    psa[i + 1] = psa[i] + robots[i]

total = psa[n]
ans = float('inf')
if t * s >= n:
    print(total)

else:
    for i in range(0, t * s + 1, s):
        r = n - (t * s - i)
        rem = psa[r] - psa[i]
        # print(f"destroying {r} - {n} and {1} - {i} {rem = }")
        ans = min(rem, ans)
    
    print(total - ans)

    
