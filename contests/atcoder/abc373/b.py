keyboard = input()
a = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
ans = 0
cur_idx = keyboard.index(a[0])
for i in range(len(a)):
    left = keyboard[cur_idx::-1]
    right = keyboard[cur_idx:]
    if a[i] in left:
        ans += left.index(a[i])
    
    if a[i] in right:
        ans += right.index(a[i])
    
    # print(left, right, ans)
    cur_idx = keyboard.index(a[i])

print(ans)
