t = int(input())
for _ in range(t):
    n = int(input())
    arr = list(map(int, input().split()))
    ans = 0
    for center in range(n):
        size = 0
        big = arr[center]
        for i in range(center - 2, -1, -2):
            size += 1
            big = max(big, arr[i])

        for i in range(center, n, 2):
            size += 1
            big = max(big, arr[i])

        ans = max(big + size, ans)
    print(ans)