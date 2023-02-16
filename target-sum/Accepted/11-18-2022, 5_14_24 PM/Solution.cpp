// https://leetcode.com/problems/target-sum

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        
        return isTargetSet(nums, nums.size(),target);
        
        
    }

    int isTargetSet(vector<int>& nums, int n,int target)
    {
        if(n==0 && target==0)
            return 1;
        else if (n==0)
        {
            return 0;
        }
        else
        {
            return isTargetSet(nums,n-1,target+nums[n-1]) + isTargetSet(nums,n-1,target-nums[n-1]);
        }
    }
};