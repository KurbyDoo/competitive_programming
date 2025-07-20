t = int(input())
for _ in range(t):
    n, q = map(int, input().split())
    psa = [0] * n
    nums = list(map(int, input().split()))
    s = list(input())
    for i in range(n):
        psa[min(nums[i] - 1, i)] += 1
        psa[max(nums[i] - 1, i)] -= 1

    for i in range(1, n):
        psa[i] += psa[i - 1]
    bad = set()

    for i in range(1, n):
        if s[i - 1] == "L" and s[i] == "R":
            if (psa[i - 1] > 0): bad.add(i - 1)
    for i in range(q):
        loc = int(input()) - 1
        if loc - 1 in bad: bad.remove(loc - 1)
        if loc in bad: bad.remove(loc)
        s[loc] = "L" if s[loc] == "R" else "R"
        if s[loc - 1] == "L" and s[loc] == "R" and psa[loc - 1] > 0: bad.add(loc - 1)
        if s[loc] == "L" and s[loc + 1] == "R" and psa[loc] > 0: bad.add(loc)
        print("YES" if len(bad) == 0 else "NO")
            