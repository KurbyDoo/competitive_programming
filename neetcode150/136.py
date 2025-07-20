class Solution(object):
    def singleNumber(self, nums):

        # Create a set (An array that does not allow duplicate elements)
        storage = set()
        for i in nums:

            # If number already in the set remove it
            if i in storage:
                storage.remove(i)

            # Add number to set
            else:
                storage.add(i)

        return list(storage)[0]
