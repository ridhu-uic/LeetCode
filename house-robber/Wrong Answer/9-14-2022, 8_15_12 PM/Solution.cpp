// https://leetcode.com/problems/house-robber

class Solution {
public:
    int rob(vector<int>& nums) {
        
        int n1,n2;
        int max1,max2;
        n1=max_element(nums.begin(),nums.end())-nums.begin();
        max1=nums[n1];
        nums[n1]=0;
        if(n1!=0)
            nums[n1-1]=0;
        if(n1!=nums.size()-1)
            nums[n1+1]=0;
        n2=max_element(nums.begin(),nums.end())-nums.begin();
        max2=nums[n2];
        
        return max1+max2;
        
        
        
    }
};