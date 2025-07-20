t = int(input())

def solve():
    n = int(input())
    sides = list(map(int, input().split()))
    s1 = set()
    s2 = set()
    sides.sort()
    for s in sides:
        if s in s1:
            s2.add(s)
        s1.add(s)

    if len(s2) == 0: return -1
    big = max(s2)
    sides.remove(big)
    sides.remove(big)
    min_diff = float('inf')
    for i in range(len(sides) - 1):
        if sides[i + 1] - sides[i] < big * 2:
            return f"{big} {big} {sides[i]} {sides[i + 1]}"
    return -1


for _ in range(t):
    print(solve())