t = int(input())
for _ in range(t):
    n = int(input())
    nums = list(map(int, input().split()))
    freq = [0] * 60
    for i in nums:
        freq[i] += 1
    print(n - max(freq))