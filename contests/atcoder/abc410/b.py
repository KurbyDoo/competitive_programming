n, q = map(int, input().split())
seq = list(map(int, input().split()))
out = []
boxes = [(0, i) for i in range(1, n + 1)]
boxes.sort(reverse=True)
for x in seq:
    if x == 0:
        small = boxes.pop()
        out.append(small[1])
        boxes.append((small[0] + 1, small[1]))
    

    else:
        out.append(x)
        for i in range(n):
            if boxes[i][1] == x:
                boxes[i] = (boxes[i][0] + 1, x)
        
    boxes.sort(reverse=True)
print(*out)