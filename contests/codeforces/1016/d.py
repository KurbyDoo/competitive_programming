t = int(input())

def find(n, x, y):
    if n == 0: return 1
    mid = (1 << (n - 1))
    if x < mid and y < mid:
        return find(n - 1, x, y)
    if x < mid:
        return find(n - 1, x, y - mid) + mid * mid * 2
    if y < mid:
        return find(n - 1, x - mid, y) + mid * mid * 3

    return find(n - 1, x - mid, y - mid) + mid * mid


def locate(n, d) -> list[int]:
    if n == 0: return [1, 1]
    mid = (1 << (n - 1))
    if d <= mid * mid:
        return locate(n - 1, d)
    if d <= mid * mid * 2:
        out = locate(n - 1, d - mid * mid)
        return [out[0] + mid, out[1] + mid]
    
    if d <= mid * mid * 3:
        out = locate(n - 1, d - mid * mid * 2)
        return [out[0] + mid, out[1]]    
    out = locate(n - 1, d - mid * mid * 3)
    return [out[0], out[1] + mid]    


for _ in range(t):
    n = int(input())
    q = int(input())

    for i in range(q):
        tp, *s = input().split()
        if tp == "->":
            print(find(n, int(s[1]) - 1, int(s[0]) - 1))
        else:
            print(*locate(n, int(s[0])))