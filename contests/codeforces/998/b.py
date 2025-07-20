t = int(input())


def solve():
    last = -1
    for i in range(m):
        for j in range(n):
            if last >= cows[j][i]: return -1
            last = cows[j][i]

    out = [cows[k][-1] for k in range(n)]
    return " ".join(list(map(str, out)))


for _ in range(t):
    n, m = map(int, input().split())
    cows = [sorted(list(map(int, input().split()))) + [k + 1] for k in range(n)]
    cows.sort()

    print(solve())