t = int(input())
for _ in range(t):
    n = int(input())
    s = input()
    print("YES" if ("11" in s or s[0] == "1" or s[-1] == "1") else "NO")