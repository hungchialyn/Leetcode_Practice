class Solution(object):
    def containsDuplicate(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        d = {}
        for num in nums:
            if d.get(num):
                return True
            d.setdefault(num, 1)
        return False
        