import sys
from collections import defaultdict
input = sys.stdin.readline

n, m = map(int, input().split())

restrictions = defaultdict(list)
for _ in range(m):
    a, b = map(int, input().split())
    restrictions[a].append(b)
    restrictions[b].append(a)

def buildPizza(remaining: list()) -> int:
    if not remaining:
        return 1

    count = 1
    for i in range(len(remaining)):
        newRemaining = []
        for topping in remaining:
            if topping not in restrictions[remaining[i]] and topping > remaining[i]:
                newRemaining.append(topping)

        count += buildPizza(newRemaining)

    return count

print(buildPizza([i + 1 for i in range(n)]))

