from collections import defaultdict

with open("contests\codingquest\p3\input.txt") as f:
    lines = f.readlines()
    output = ""
    for line in lines:
        nums = list(map(int, line.split()))
        thing = 0
        for n in nums:
            if thing % 2 == 0:
                output += "." * n

            else:
                output += "#" * n
            
            thing += 1

        counter = 0
        for c in output:
            counter += 1
            print(c, end="")
            if counter == 100:
                counter = 0
                print()
            


