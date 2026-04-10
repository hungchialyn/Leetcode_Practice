# 限 a>=0 and b>=0
class Solution(object):
    def getSum(self, a, b):
        """
        :type a: int
        :type b: int
        :rtype: int
        """
        MASK = 0xFFFFFFFF
        a=a&MASK
        b=b&MASK
        abAND = a&b
        abOR = a|b
        carry = 0
        res = 0
        count = 0
        while(abAND or abOR or carry):
            print(res)
            if((abAND&1) | (abOR&1) | carry):
                if((abAND&1) | (abOR&1)):
                    if((abAND&1) & (abOR&1)):
                        res += (carry&1)<<count
                        carry=1
                    else:
                        if(carry):
                            carry=1
                        else:
                            res += 1<<count
                else:
                    res += (carry&1)<<count
                    carry=0
            
            count+=1
            abAND>>=1
            abOR>>=1
        
        return res