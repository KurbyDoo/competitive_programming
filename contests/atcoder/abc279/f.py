import sys

input = sys.stdin.readline
N, Q = map(int, input().split())
ball_location = {i: i for i in range(1, N + 1)}
box_contents = {i: [i] for i in range(1, N + 1)}
k = N

for _ in range(Q):
    query = list(map(int, input().split()))
    op_type = query[0]

    if op_type == 1:
        X, Y = query[1], query[2]
        if Y not in box_contents: continue
        if X not in box_contents: box_contents[X] = []

        if len(box_contents[X]) < len(box_contents[Y]):
            box_contents[X], box_contents[Y] = box_contents[Y], box_contents[X]
            for ball in box_contents[X]:
                ball_location[ball] = X

        balls_to_move = box_contents.pop(Y)
        for ball in balls_to_move:
            ball_location[ball] = X
        box_contents[X].extend(balls_to_move)

    elif op_type == 2:
        X = query[1]
        k += 1

        if X not in box_contents: box_contents[X] = []
        box_contents[X].append(k)
        ball_location[k] = X

    elif op_type == 3:
        X = query[1]
        print(ball_location[X])
