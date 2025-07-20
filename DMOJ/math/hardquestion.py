import math
g = float(input())
c = float(input())
t = float(input())

# t_sound = t - t_stone
# d_sound = d_stone
# t_sound * c = g * t_stone * t_stone / 2
# t * c - t_stone * c = g * t_stone * t_stone / 2
# 0 = (g / 2)x^2 + (c)x - t*c
# x = (-c + sqrt(c ^ 2 + 2 * g * t * c)) / g
t_stone = (-c + math.sqrt(c * c + 2 * g * t * c)) / g
d = g * (t_stone * t_stone) / 2
print(d)
print(d * 2 / t_stone)
