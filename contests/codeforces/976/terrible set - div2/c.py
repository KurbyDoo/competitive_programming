t = int(input())
for _ in range(t):
    b, c, d = map(int, input().split())
    bin_b = bin(b)[2:]
    bin_c = bin(c)[2:]
    bin_d = bin(d)[2:]
    max_length = max([len(bin_b), len(bin_c), len(bin_d)])
    if len(bin_b) < max_length: bin_b = "0" * (max_length - len(bin_b)) + bin_b
    if len(bin_c) < max_length: bin_c = "0" * (max_length - len(bin_c)) + bin_c
    if len(bin_d) < max_length: bin_d = "0" * (max_length - len(bin_d)) + bin_d

    bin_a = ""
    for i in range(max_length):
        if bin_b[i] == '0' and bin_c[i] == '1': bin_a += "0"
        elif bin_b[i] == '1' and bin_c[i] == '0': bin_a += "1"
        elif bin_b[i] == "0" and bin_c[i] == "0": bin_a += bin_d[i]
        else: bin_a += "0" if bin_d[i] == "1" else "1"
    
    # print(bin_a)
    # print(bin_b)
    # print(bin_c)
    # print(bin_d)
    ans = int(bin_a, 2)
    # print(ans)

    if (ans | b) - (ans & c) != d:
        print(-1)
    else:
        print(ans)
