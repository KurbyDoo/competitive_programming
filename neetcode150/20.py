from collections import deque
class Solution:
    def isValid(self, s: str) -> bool:
        q = deque()
        past = ""

        for c in list(s):
            if c in ['(', '[', '{']:
                q.append(c)

            else:
                if q:
                    past = q.pop()

                else:
                    return False

                if past + c not in ['()', '[]', '{}']:
                    return False

        if q:
            return False
        return True
