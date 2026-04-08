class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        length = len(prices)
        res = 0
        left = 0
        right = 1
        while (left != length) and (right<length):
            # print(left, right)
            if(prices[right]>prices[left]):
                new = prices[right]-prices[left]
                if(new>res):
                    res = new
                right+=1
            else:
                if(left+1==right):
                    left+=1
                    right+=1
                else:
                    left+=1
        return res
        