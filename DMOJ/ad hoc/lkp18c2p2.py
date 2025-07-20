n, k = map(int, input().split())
off = [0] * k
cur_sum = 0
nums = list(map(int, input().split()))
ans = 0
off[0] = 1
for a in nums:
    cur_sum += a
    ans += off[(k - (cur_sum % k)) % k]
    off[cur_sum % k] += 1
    # print(*off)
print(ans)
