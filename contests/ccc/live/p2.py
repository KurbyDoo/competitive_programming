from collections import defaultdict
t, n = map(int, input().split())
for _ in range(t):
    thing = defaultdict(int)
    string = input()
    if n > 52:
        print("F")

    else:
        out = "T"
        for c in string:
            thing[c] += 1

        last = thing[string[0]] == 1
        for i in range(1, n):
            if last and thing[string[i]] == 1:
                out = "F"
                break

            elif not last and thing[string[i]] != 1:
                out = "F"
                break

            last = thing[string[i]] == 1

        print(out)