# Author: KurbyDoo
# Creation Date: Jul 19, 2025
# Problem Link: https://dmoj.ca/problem/ccc14s3
# Problem Name: CCC '14 S3 - The Geneva Confection
# Status: Solved
# Notes:
#     Original creation date unknown
#     
#     
#     
import sys
from collections import deque
input = sys.stdin.readline

t = int(input())

for _ in range(t):
    n = int(input())
    cur = 1
    output = "N"
    mountain = deque()
    branch = deque()
    lake = deque()

    for _ in range(n):
        mountain.append(int(input()))

    mCart = None
    bCart = None
    while True:
        if mountain:
            mCart = mountain.pop()
            # print(f"{mCart = }")

        if branch:
            bCart = branch.pop()
            # print(f"{bCart = }")

        if mCart == cur:
            # print(f"moving {mCart = } to lake")
            lake.append(mCart)
            mCart = None
            cur += 1

        elif bCart == cur:
            # print(f"moving {bCart = } to lake")
            lake.append(bCart)
            bCart = None
            cur += 1

        else:
            if not bCart and not mCart:
                # print(f"{mountain = }, {branch = }")
                output = "Y"
                break

            elif mCart:
                if bCart:
                    # print(f"moving {bCart = } to branch")
                    branch.append(bCart)
                    bCart = None
                
                # print(f"moving {mCart = } to branch")
                branch.append(mCart)
                mCart = None
                # print(list(branch))

            else:
                # print(f"{bCart = }, {mCart = }")
                break
                
        if bCart:
            branch.append(bCart)
            bCart = None

        if mCart:
            mountain.append(mCart)
            mCart = None

        # print('----------')

    
    print(output)
        



