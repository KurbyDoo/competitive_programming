n = int(input())

def check(a, b):
    m = min(len(a), len(b))

    isPre = True
    isSuf = True
    for i in range(m):
        if not (a[i] == b[i]):
            isPre = False
            
        if not (a[-i - 1] == b[-i - 1]):
            isSuf = False

    if isPre or isSuf:
        return True

    return False

for _ in range(n):
    a = input()
    b = input()
    c = input()

    if check(a, b) or check(b, c) or check(a, c):
        print("No")

    else:
        print("Yes")
