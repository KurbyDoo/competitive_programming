dp = {}
def givePies(pies: int, people: int):
    if pies < people:
        return 0
    if pies == people or people == 1:
        return 1

    if dp.get((pies, people), False):
        return dp[(pies, people)]

    dp[(pies, people)] = givePies(pies - people, people) + givePies(pies - 1, people - 1)
    return dp[(pies, people)]


n = int(input())
k = int(input())

print(givePies(n, k))
