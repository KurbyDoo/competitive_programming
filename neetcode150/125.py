import re

class Solution(object):
    def isPalindrome(self, s):
        """
        :type s: str
        :rtype: bool
        """
        s = list(re.sub("[^a-zA-Z0-9]+", "", s).lower())
        for i in range(len(s) // 2):
            if s[i] != s[-i - 1]:
                return False

        return True
