n = int(input())

for _ in range(n):
    n1, n2 = input().split()

    if n1[-2:] == "17" or n2[-2:] == "17":
        print("NO")

    elif n1[-1:] == "7" and n2[-2:] == "11":
        print("YES")

    elif n2[-1:] == "7" and n1[-2:] == "11":
        print("YES")

    else: print("NO")
