from collections import defaultdict

class Solution:
    def ladderLength(self, beginWord: str, endWord: str, wordList: list[str]) -> int:
        a = defaultdict(list)

        for i in wordList:
            for l in range(len(beginWord)):
                a[i[:l] + "*" + i[l+1:]].append(i)

        visited = {}

        q = [[beginWord, 1]]
        while q:
            cur, count = q.pop(0)

            if cur == endWord:
                return count

            print(f"checking {cur}")
            for i in range(len(cur)):
                new = cur[0:i] + "*" + cur[i + 1:]
                print(f"{new = } {cur[0:i] + '*' + cur[i + 1:]}")
                for w in a[new]:
                    if not visited.get(w, False):
                        q.append([w, count + 1])
                        visited[w] = True

        return 0
