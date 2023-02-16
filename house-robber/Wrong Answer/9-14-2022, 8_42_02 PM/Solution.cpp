// https://leetcode.com/problems/house-robber

class Solution {
public:
    int rob(vector<int>& nums) {
        
        if(accumulate(nums.begin(),nums.end(),0)==0)
            return 0;
        else
        {
            int n=max_element(nums.begin(),nums.end())-nums.begin();
            int max=nums[n];
            nums[n]=0;
            if(n!=0)
                nums[n-1]=0;
        
            if(n!=nums.size()-1)
                nums[n+1]=0;
            
            return max + rob(nums);
            
        }
      
        
    }
};