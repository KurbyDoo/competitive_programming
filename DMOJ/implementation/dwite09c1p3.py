for _ in range(5):
    n = int(input())
    expected = ((n + 1) * (n + 2)) // 2
    sum = 0
    for _ in range(n):
        sum += int(input())

    print(expected - sum)