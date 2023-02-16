// https://leetcode.com/problems/house-robber

class Solution {
public:
    int rob(vector<int>& nums) {
     vector<int> theft;
     int n=nums.size();

     if(n==1)
        return nums[0];
     if(n==2)
        return max(nums[0],nums[1]);
     theft.resize(n);
     theft[0]=nums[0];
     theft[1]=max(nums[0],nums[1]);
     for(int i=2;i<n;i++)
     {
         theft[i]=max(theft[i-1],nums[i]+theft[i-2]);
     }
     return theft[n-1];
    }
};