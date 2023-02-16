// https://leetcode.com/problems/next-permutation

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        
        int i=nums.size()-1;
        
        while(i>0 && nums[i-1]>nums[i])
        {
            i--;
            }
        
        if(i!=0)
        {
            int exval=nums[i];
            nums[i]=nums[i-1];
            nums[i-1]=exval;
        }
        
        sort(nums.begin()+i,nums.end());
        
        
        
        
        
        
    }
};