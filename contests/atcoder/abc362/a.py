r, g, b = map(int, input().split())
c = input()

ans = float('inf')

if c == "Blue":
    ans = min(r, g)

elif c == "Red":
    ans = min(b, g)

elif c == "Green":
    ans = min(r, b)
print(ans)