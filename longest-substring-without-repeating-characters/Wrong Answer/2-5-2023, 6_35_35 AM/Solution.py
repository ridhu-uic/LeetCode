// https://leetcode.com/problems/longest-substring-without-repeating-characters

class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        
        maxcount = 0
        count=0
        for k in range(len(s)):
            s1 = set()
            for l in range(k,len(s)):
                if s[l] in s1:
                    if count > maxcount:
                        maxcount=count
                    count=1
                    s1 = set([s[l]])
                else:
                    count+=1
                    s1.add(s[l])
                    
                print(len(s1),"\n")
                
        return maxcount
                
            
                
            
            
        
        
        
        