nums = []
while (temp := int(input())) != 0:
    nums.append(temp)

print(0)
nums.reverse()
print("\n".join(list(map(str, nums))))