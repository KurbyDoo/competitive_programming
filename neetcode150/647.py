class Solution(object):
    def countSubstrings(self, s):
        """
        :type s: str
        :rtype: int
        """

        noStrings = 0

        for i in range(len(s)):
            l, r = i, i
            while (l >= 0 and r < len(s)) and s[l] == s[r]:
                noStrings += 1
                l -= 1
                r += 1

            l, r = i, i + 1
            while (l >= 0 and r < len(s)) and s[l] == s[r]:
                noStrings += 1
                l -= 1
                r += 1

        return noStrings
