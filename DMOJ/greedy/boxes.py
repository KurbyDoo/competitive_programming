import sys
input = sys.stdin.readline

best = [0 for _ in range(1000000)]
for _ in range(int(input())):
    w, h = list(map(int, input().split()))
    best[w - 1] = max(h, best[w - 1])

print(sum(best))