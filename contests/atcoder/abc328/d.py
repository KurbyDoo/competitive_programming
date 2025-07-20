s = input()
stack = []

for c in s:
    stack.append(c)
    if len(stack) >= 3:
        if (stack[-3] + stack[-2] + stack[-1] == 'ABC'):
            stack.pop()
            stack.pop()
            stack.pop()
print("".join(stack))