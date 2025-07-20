n = int(input())

def solve():
    string = input().split()

    if len(string) == 3:
        print(" ".join(string))
        return
    
    while "X" in string:
        xIndex = string.index("X")
        string = string[:xIndex - 1] + [f"({string[xIndex - 1]} {string[xIndex]} {string[xIndex + 1]})"] + string[xIndex + 2:]

        if len(string) == 3:
            print(" ".join(string))
            return

    while "-" in string or "+" in string:
        dash, plus = float("inf"), float("inf")
        if "-" in string:
            dash = string.index("-")

        if "+" in string:
            plus = string.index("+")

        i = min(dash, plus)
        string = string[:i - 1] + [f"({string[i - 1]} {string[i]} {string[i + 1]})"] + string[i + 2:]

        if len(string) == 3:
            print(" ".join(string))
            return
    
    print(" ".join(string))

for _ in range(n - 1):
    solve()
    print()

solve()
