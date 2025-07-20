for _ in range(10):
    n = list(input())
    
    cur_place = 0
    output = []
    while n:
        next_digit = n[-1]
        next_two_digit = (n[-2] + n[-1]) if len(n) >= 2 else 50
        if int(next_two_digit) <= cur_place:
            output.append(next_two_digit)
            n.pop()
            n.pop()

        elif int(next_digit) <= cur_place:
            output.append(next_digit)
            n.pop()

        else:
            output.append("0")

        cur_place += 1

    
    print(" ".join(output[::-1]))

