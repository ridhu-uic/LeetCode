// https://leetcode.com/problems/partition-equal-subset-sum

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum=0;
        int subsum=0;
        for(int i=0;i<nums.size();i++)
            sum=sum+nums[i];

        if(sum%2==1 )
            return false;

        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]+subsum<=sum/2)
                subsum=subsum+nums[i];
        }
        if(subsum==sum/2)
            return true;

        return false;
    }
};