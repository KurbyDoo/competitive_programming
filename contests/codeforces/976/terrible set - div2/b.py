import math
import decimal
t = int(input())
with decimal.localcontext() as ctx:
    ctx.prec = 300
    for _ in range(t):
        k = decimal.Decimal(input())
        ans = k + int(k.sqrt())
        # if int(math.sqrt(k)) * int(math.sqrt(k)) == k:
        # print("bef", needed + )
        l = k
        r = k * 2
        while l < r:
            mid = (l + r) // 2
            temp = mid - int(mid.sqrt())
            # print(l, r)
            if temp == k:
                l = mid
                r = mid - 1

            elif temp > k:
                r = mid - 1

            else:
                l = mid + 1

        print(l)