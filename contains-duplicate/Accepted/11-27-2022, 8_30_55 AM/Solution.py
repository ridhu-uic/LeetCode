// https://leetcode.com/problems/contains-duplicate

class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        dict = {}

        for i in nums:
            if dict.get(i,"x") == "x":
                dict[i]="1"

            else:
                return True

        return False