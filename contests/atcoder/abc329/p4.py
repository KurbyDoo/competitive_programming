import sys
input = sys.stdin.readline
total_votes = [0] * 200010
n, m = map(int, input().split())
votes = list(map(int, input().split()))
best = (0, -1)
for i in range(m):
    total_votes[votes[i]] += 1
    if (total_votes[votes[i]] > best[0]) or (total_votes[votes[i]] == best[0] and votes[i] < best[1]):
        best = (total_votes[votes[i]], votes[i])
    print(best[1])