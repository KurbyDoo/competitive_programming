n = int(input())
s = input()
count = 0
for i in range(n):
    if s[-i - 1] == 'N':
        count += 1
    
    else:
        break

if count >= ((n + 1) // 2):
    print("NO")

else:
    print("YES")