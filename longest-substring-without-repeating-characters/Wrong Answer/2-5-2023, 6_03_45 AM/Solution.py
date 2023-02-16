// https://leetcode.com/problems/longest-substring-without-repeating-characters

class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        
        maxcount = 0
        s1 = ""
        count=0
        for k in s:
            
            if k in s1:
                if count > maxcount:
                    maxcount=count
                count=0
                s1=""
            else:
                count+=1
                s1=s1+k
                
        return maxcount
                
            
                
            
            
        
        
        
        