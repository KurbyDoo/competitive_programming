# Author: KurbyDoo
# Creation Date: Jul 19, 2025
# Problem Link: https://dmoj.ca/problem/dwite07c2p4
# Problem Name: DWITE '07 R2 #4 - All Is Balanced
# Status: Solved
# Notes:
#     Original creation date unknown
#     
#     
#     
for _ in range(5):
    s = list(input())
    output = "balanced"

    stack = []
    for c in s:
        if c in list("{[("):
            stack.append(c)

        elif c in list("}])"):
            if stack:
                # print(f'{c = }{stack = }')
                if stack[-1] == '{' and c == '}':
                    stack.pop()

                elif stack[-1] == '(' and c == ')':
                    stack.pop()

                elif stack[-1] == '[' and c == ']':
                    stack.pop()

                else:
                    output = 'not balanced'
                    break

            else:
                output = 'not balanced'
                break

    if stack:
        output = 'not balanced'

    print(output)