class Solution(object):
    def isAnagram(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        rem = [0]*26
        for letter in s:
            rem[ord(letter)-97]+=1
        for letter in t:
            rem[ord(letter)-97]-=1
        for i in range(len(rem)):
            if(rem[i]!=0):
                return False
        return True
        