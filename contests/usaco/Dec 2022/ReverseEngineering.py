def check_program(program, pairs):
    for i, o in pairs:
        if program(i) != o:
            return False
    return True

def generate_programs(n):
    if n == 0:
        yield lambda x: 0
    else:
        for p in generate_programs(n-1):
            yield lambda x: p(x)
            yield lambda x: x[n-1] if p(x) == 0 else p(x)

t = int(input())

for _ in range(t):
    input()
    n, m = map(int, input().split())

    pairs = []
    output = "LIE"
    for _ in range(m):
        i, o = input().split()
        i = list(map(int, list(i)))
        o = int(o)
        pairs.append((i, o))
        
    for program in generate_programs(n):
        if check_program(program, pairs):
            output = "OK"
            break


    print(output)

