t = int(input())
for _ in range(t):
    n, k = map(int, input().split())
    cards = list(map(int, input().split()))
    sum_cards = sum(cards)
    min_partition = max(cards)
    ans = 0
    for i in range(1, n + 1):
        partitions = max(min_partition, (sum_cards + i - 1) // i)
        rem = (partitions * i - sum_cards)
        if k >= rem:
            ans = max(ans, i)
    print(ans)