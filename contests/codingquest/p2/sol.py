from collections import defaultdict

with open("contests\codingquest\p2\input.txt") as f:
    lines = f.readlines()
    internal = 0
    passenger = 0
    for line in lines:
        length = int(line[4:8], 16)
        source = [int(line[24 + i * 2:26 + i * 2], 16) for i in range(4)]
        dest = [int(line[32 + i * 2:34 + i * 2], 16) for i in range(4)]
        if (source[0] == 192 and source[1] == 168 and 0 <= source[2] <= 254 and 0 <= source[3] <= 254) or (dest[0] == 192 and dest[1] == 168 and 0 <= dest[2] <= 254 and 0 <= dest[3] <= 254):
            internal += length

        if (source[0] == 10 and source[1] == 0 and 0 <= source[2] <= 254 and 0 <= source[3] <= 254) or (dest[0] == 10 and dest[1] == 0 and  0 <= dest[2] <= 254 and 0 <= dest[3] <= 254):
            passenger += length
        
        # print(f"{length = } {source = } {dest = }")        
    # 4500 0377 000000008306f39f 0A000bc1 d7253441
    print(f"{internal}/{passenger}")