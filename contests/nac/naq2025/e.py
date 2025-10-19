redscore = 0
yellowscore = 0
cx = 144
cy = 84
for _ in range(10):
    red = list(map(int, input().split()))
    yellow = list(map(int, input().split()))
    cr, cyy = 999999999, 999999999
    # print(f"{red[0] = } {yellow[0] = }")
    for i in range(1, red[0] + 1):
        x = red[2 * i - 1]
        y = red[2 * i]
        dist = (x - cx) * (x - cx) + (y - cy) * (y - cy)
        # print(f"{dist = } {x = } {y = }")
        cr = min(cr, dist)

    for i in range(1, yellow[0] + 1):
        x = yellow[2 * i - 1]
        y = yellow[2 * i]
        dist = (x - cx) * (x - cx) + (y - cy) * (y - cy)
        cyy = min(cyy, dist)

    if cr < cyy:
        for i in range(1, red[0] + 1):
            x = red[2 * i - 1]
            y = red[2 * i]
            dist = (x - cx) * (x - cx) + (y - cy) * (y - cy)
            if dist < cyy:
                redscore += 1

    else:
        for i in range(1, yellow[0] + 1):
            x = yellow[2 * i - 1]
            y = yellow[2 * i]
            dist = (x - cx) * (x - cx) + (y - cy) * (y - cy)
            if dist < cr:
                yellowscore += 1
    
    # print(cr, cyy)

print(redscore, yellowscore)