# Author: KurbyDoo
# Creation Date: Jul 19, 2025
# Problem Link: https://dmoj.ca/problem/coci17c7p3
# Problem Name: COCI '17 Contest 7 #3 Go
# Status: Solved
# Notes:
#     Original creation date unknown
#     
#     
#     
n = int(input())
pokemon = {}

for _ in range(n):
    poke = input()
    cost, amount = list(map(int, input().split()))
    no_evo = 0
    while amount >= cost:
        no_evo += amount//cost
        amount -= (((amount//cost) * cost) - (2 * (amount//cost)))
    pokemon[poke] = no_evo

total = 0
m = 0
m_name = ""
for name, i in pokemon.items():
    if i > m:
        m = i
        m_name = name
    
    total += i

print(total)
print(m_name)
