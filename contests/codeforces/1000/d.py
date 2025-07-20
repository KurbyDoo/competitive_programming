t = int(input())

def solve():
    n, m = map(int, input().split())
    top = list(map(int, input().split()))
    bot = list(map(int, input().split()))
    top.sort()
    bot.sort()

    top_pairs = [0] * (n + m)
    bot_pairs = [0] * (n + m)
    for i in range(n//2):
        top_pairs[i + 1] += top[-i - 1] - top[i] + top_pairs[i]
    for i in range(m//2):
        bot_pairs[i + 1] += bot[-i - 1] - bot[i] + bot_pairs[i]

    ans = []
    for i in range(1, (n + m)//3):
        

        best = 0
        for j in range(i + 1):
            if n - j * 2 - (i - j) < 0: continue
            if m - (i - j) * 2 - j < 0: continue
            best = max(best, top_pairs[j] + bot_pairs[i - j])
        if best == 0: break
        ans.append(best)
    
    print(len(ans))
    print(*ans)

for _ in range(t):
    solve()

