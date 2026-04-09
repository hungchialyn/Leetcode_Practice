# 暴力法 O(n^2 * k)
class Solution(object):
    def anagram(self, str, key):
        rem = [0]*26
        for letter in str:
            rem[ord(letter)-97]+=1
        for letter in key:
            rem[ord(letter)-97]-=1
        for i in range(26):
            if(rem[i]!=0):
                return False
        return True

    def groupAnagrams(self, strs):
        """
        :type strs: List[str]
        :rtype: List[List[str]]
        """
        dic = {}
        for s in strs:
            found = False
            for key in dic:
                if(self.anagram(s, key)):
                    dic.setdefault(key, []).append(s)
                    found = True
                    break
            if not found:
                dic[s] = [s]
        return list(dic.values())
            
# 排序法
class Solution(object):
    def groupAnagrams(self, strs):
        """
        :type strs: List[str]
        :rtype: List[List[str]]
        """
        d = {}
        for s in strs:
            key = ''.join(sorted(s))
            d.setdefault(key, []).append(s)
        return list(d.values())
        
# 26字母計數 -> 最快
class Solution(object):
    def groupAnagrams(self, strs):
        d = {}

        for s in strs:
            count = [0]*26
            for c in s:
                count[ord(c)-97] += 1
            
            key = tuple(count)
            d.setdefault(key, []).append(s)

        return list(d.values())