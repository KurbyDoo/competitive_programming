from collections import defaultdict


class Solution(object):
    def groupAnagrams(self, strs):
        """
        :type strs: List[str]
        :rtype: List[List[str]]
        """
        past = defaultdict(list)

        for i in strs:
            counter = [0] * 26
            for letter in i:
                counter[ord(letter) - ord('a')] += 1

            past[tuple(counter)].append(i)

        output = []
        for i in past.values():
            output.append(i)

        return output
