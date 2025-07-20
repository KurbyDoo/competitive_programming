from functools import lru_cache

@lru_cache
def givePies(pies: int, people: int):
    if pies < people:
        return 0
    if pies == people or people == 1:
        return 1

    return givePies(pies - people, people) + givePies(pies - 1, people - 1)


n = int(input())
k = int(input())

print(givePies(n, k))
