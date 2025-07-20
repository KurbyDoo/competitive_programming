n, m = map(int, input().split())
problems = list(map(int, input().split()))
points = []
solves = []
best_score = 0
for i in range(1, n + 1):
    p = input()
    score = i
    for j in range(m):
        if p[j] == "o":
            score += problems[j]

    solves.append(p)

    best_score = max(score, best_score)
    points.append(score)

sorted_problems = []
for i in range(m):
    sorted_problems.append((problems[i], i))

sorted_problems.sort(reverse=True)
for i in range(n):
    cur_point = points[i]
    cur_solve = solves[i]
    count = 0
    # print(cur_point, cur_solve)
    for s, j in sorted_problems:
        if cur_point >= best_score: break
        if cur_solve[j] == "o": continue
        cur_point += s
        count += 1

    print(count)

