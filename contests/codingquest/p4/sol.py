from collections import defaultdict
import math
stars = []
with open("contests\codingquest\p4\input.txt") as f:
    lines = f.readlines()
    for line in lines[1:]:
        things = line.split()
        stars.append((float(things[-1]), float(things[-2]), float(things[-3])))

    min_score = float('inf')
    for i in range(len(stars)):
        for j in range(i + 1, len(stars)):
            dist = (stars[i][0] - stars[j][0]) * (stars[i][0] - stars[j][0])
            dist += (stars[i][1] - stars[j][1]) * (stars[i][1] - stars[j][1])
            dist += (stars[i][2] - stars[j][2]) * (stars[i][2] - stars[j][2])
            # print(dist)
            min_score = min(min_score, dist)

    print(math.sqrt(min_score))


            


