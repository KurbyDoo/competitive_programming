target = input()
reachable = [float('inf') for _ in range(len(target) + 1)]
n = int(input())
reachable[0] = 0

for i in range(n): #100
    a, *strings = input().split()
    a = int(a)

    to_update = []
    for s in strings: #10
        for c in range(len(target) - len(s) + 1): #100
            # print(c, target[c:c+len(s)], s)
            if reachable[c] + 1 < reachable[c + len(s)] and target[c:c+len(s)] == s:
                to_update.append((c + len(s), reachable[c] + 1))
                # reachable[c + len(s)] = reachable[c] + 1

    for a, b in to_update:
        reachable[a] = min(reachable[a], b)

        # print(*reachable)
                
print(-1 if reachable[-1] == float('inf') else reachable[-1])

# abcde
# 1
# 5 a b c d e
