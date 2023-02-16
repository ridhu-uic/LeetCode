// https://leetcode.com/problems/contains-duplicate-ii

class Solution:
    def containsNearbyDuplicate(self, nums: List[int], k: int) -> bool:
        hash = {}
        count = 0
        for i in nums:
            
            if hash.get(i,"x") == "x":
                hash[i]=count
            else:
                if count - hash.get(i) <= k:
                    return True
                else:
                    hash[i]=count
            count=count+1
        return False
