from collections import defaultdict
t = int(input())
def solve():
    n, m = map(int, input().split())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))
    a_dict = defaultdict(int)
    a_rem = []
    b_rem = []
    a.sort(reverse=True)
    b.sort(reverse=True)
    while a and b:
        if a[-1] == b[-1]:
            a.pop()
            b.pop()
        elif a[-1] < b[-1]: a_rem.append(a.pop())
        else: b_rem.append(b.pop())
    a.extend(a_rem)
    b.extend(b_rem)
    # print(f"{a = }")
    # print(f"{b = }")
    for a1 in a:
        a_dict[a1] += 1
    ops = n - m
    if ops < 0: return "No"
    
    while b:
        nxt = b.pop()
        # print(f"{nxt = }")
        if a_dict[nxt] != 0:
            a_dict[nxt] -= 1

        elif nxt == 1:
            return "No"
        elif nxt % 2 == 0:
            b.append(nxt // 2)
            b.append(nxt // 2)
        else:
            b.append(nxt // 2 + 1)
            b.append(nxt // 2)
            
    return "Yes" if sum(a_dict.values()) + len(b) == 0 else "No"

for _ in range(t):
    print(solve())