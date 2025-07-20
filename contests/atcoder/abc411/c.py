ans = 0
n, q = map(int, input().split())
squares = [False] * (n + 2)
queries = list(map(int, input().split()))
for ai in queries:
    if squares[ai]:
        if not squares[ai - 1] and not squares[ai + 1]:
            ans -= 1
        
        elif squares[ai - 1] and squares[ai + 1]:
            ans += 1
        
    else:
        if not squares[ai - 1] and not squares[ai + 1]:
            ans += 1

        elif squares[ai - 1] and squares[ai + 1]:
            ans -= 1
    squares[ai] = not squares[ai]
    print(ans)