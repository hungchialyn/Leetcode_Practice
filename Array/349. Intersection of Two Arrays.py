class Solution(object):
    def intersection(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: List[int]
        """
        res = list()
        d = {}
        for n1 in nums1:
            d.setdefault(n1, 1)
        for n2 in nums2:
            if d.get(n2):
                res.append(n2)
                del d[n2]
        return res