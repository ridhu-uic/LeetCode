// https://leetcode.com/problems/contains-duplicate

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
    
        
        for (int i=0;i<nums.size();i++)
        {
            for(int j=0;j<nums.size();j++)
            {
                if(i==j)
                {
                    
                }
                else{
                    if(nums[i]==nums[j])
                        return true;
                    }
            }
            
            }
        return false;
    }
};