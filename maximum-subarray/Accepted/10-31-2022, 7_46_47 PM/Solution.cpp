// https://leetcode.com/problems/maximum-subarray

class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        int maxEndingHere=nums[0];
        int maxn=nums[0];
    
        for (int i=1;i<nums.size();i++)
        {
            maxEndingHere=max(maxEndingHere+nums[i],nums[i]);
            maxn=max(maxn,maxEndingHere);
        }
        return maxn;
    }
};