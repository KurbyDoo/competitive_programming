import os
dir_path = os.path.dirname(os.path.realpath(__file__))
print(dir_path)
# f = open(dir_path + "\\test.txt", '+r')
# out = open(dir_path + "\\test_out.txt", '+w')
f = open(dir_path + "\\line_of_delivery_part_1_input.txt", '+r')
out = open(dir_path + "\\line_of_delivery_part_1_output.txt", '+w')
t = int(f.readline())
for case in range(t):
    n, g = map(int, f.readline().split())
    energy = []
    min_dist = (10000010, -1)
    for i in range(n):
        energy.append(int(f.readline()))

    energy.sort(reverse=True)
    for i in range(1, n + 1):
        if abs(g - energy[i - 1]) < min_dist[0]:
            min_dist = (abs(g - energy[i - 1]), i)

    out.write(f"Case #{case + 1}: {min_dist[1]} {min_dist[0]}\n")

f.close()
out.close()
