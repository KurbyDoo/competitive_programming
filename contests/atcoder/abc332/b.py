k, g, m = map(int, input().split())

cur_g = 0
cur_m = 0
for i in range(k):
    if cur_g == g:
        cur_g = 0

    elif cur_m == 0:
        cur_m = m

    else:
        if cur_m > g - cur_g:
            cur_m -= (g - cur_g)
            cur_g = g
        
        else:
            cur_g += cur_m
            cur_m = 0

    # print(cur_g, cur_m)

print(cur_g, cur_m)