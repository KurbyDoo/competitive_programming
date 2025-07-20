from sys import stdout, exit
from collections import defaultdict

t = int(input())
for _ in range(t):
    n = int(input())
    if n == -1: break
    s = ""

    next_char = "0"
    move_count = 0
    searching_front = True
    while searching_front:
        if len(s) == n: break
        print(f"? {s + next_char}")
        # stdout.flush()

        move_count += 1
        ans = int(input())

        if ans == -1: exit()
        if ans == 1:
            s += next_char
            next_char = "0"

        elif next_char == "0":
            next_char = "1"
            if move_count == 1:
                s = "1" * n

        else:
            searching_front = False

    next_char = "0"
    searching_back = True
    while searching_back:
        if len(s) == n:
            print(f"! {s}")
            # stdout.flush()

            break

        print(f"? {next_char + s}")
        # stdout.flush()
        ans = int(input())
        move_count += 1
        if ans == -1: exit()
        if ans == 1:
            s = next_char + s

        else:
            s = "1" + s