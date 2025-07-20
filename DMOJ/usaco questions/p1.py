def test_num(number):
    moos = number // 3 + number // 5 - number // 15
    return moos

n = int(input())

l = n
r = n * 2
ans = 0
while l < r:
    mid = (l + r) // 2
    res = mid - test_num(mid)
    if res < n:
        l = mid + 1
    
    else:
        r = mid

print(l)
