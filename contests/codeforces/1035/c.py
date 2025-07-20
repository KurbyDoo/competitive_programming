t = int(input())

def solve():
    n, l, r, k = map(int, input().split())
    if n % 2:
        return l
    if n == 2:
        return -1
    
    next_2 = 1
    while next_2 <= l:
        next_2 *= 2
    if next_2 > r:
        return - 1
    if k < n - 1:
        return l
    return next_2
while t:
    t -= 1
    print(solve())