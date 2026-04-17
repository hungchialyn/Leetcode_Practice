class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        for i, element1 in enumerate(nums):
            for j, element2 in enumerate(nums):
                if i==j:
                    continue
                if (element1+element2) ==target:
                    return[i,j] 
        

class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        m={}
        for i, num in enumerate(nums):
            complement = target - num
            if complement in m:
                return [m[complement], i]
            m[num] = i
        