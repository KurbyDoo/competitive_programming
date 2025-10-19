def query(s):
    print(s, flush=True)
    return int(input())

top3x3 = query("? 2 2")
# ooooo
# o?ooo
# ooooo
# ooooo
# ooooo
if top3x3:
    # ooxxx
    # ?oxxx
    # xxxxx
    # xxxxx
    # xxxxx
    top3x2 = query("? 2 1")
    if top3x2:
        # ?xxxx
        # oxxxx
        # xxxxx
        # xxxxx
        # xxxxx
        ans = query("? 1 1")
        print("! 1 1" if ans else "! 2 1", flush=True)
    
    else:
        # xoxxx
        # xoxxx
        # xxxxx
        # xxxxx
        # xxxxx
        ans = query("? 1 2")
        print("! 1 2" if ans else "! 2 2", flush=True)
        
else:
    # xxoox
    # xxoox
    # oooox
    # o?oox
    # xxxxx
    botleft = query("? 4 2")
    if botleft:
        # xxxxx
        # xxxxx
        # ooxxx
        # ?oxxx
        # xxxxx
        ans = query("? 4 1")
        if ans:
            print("! 3 1" if query("? 3 1") else "! 4 1", flush=True)
        else:
            print("! 3 2" if query("? 3 2") else "! 4 2", flush=True)
    else:
        # xxoox
        # xxo?x
        # xxoox
        # xxoox
        # xxxxx
        topright = query("? 2 4")
        if topright:
            # xxoox
            # xx?ox
            # xxxxx
            # xxxxx
            # xxxxx
            ans = query("? 2 3")
            if ans:
                print("! 1 3" if query("? 1 3") else "! 2 3", flush=True)
            else:
                print("! 1 4" if query("? 1 4") else "! 2 4", flush=True)
        else:
            # xxxxx
            # xxxxx
            # xxoox
            # xx?ox
            # xxxxx
            ans = query("? 4 3")
            if ans:
                print("! 3 3" if query("? 3 3") else "! 4 3", flush=True)
            else:
                print("! 3 4" if query("? 3 4") else "! 4 4", flush=True)
