x, y = map(int, input().split())
diff = y - x
if diff > 2 or diff < -3:
    print("No")

else:
    print("Yes")