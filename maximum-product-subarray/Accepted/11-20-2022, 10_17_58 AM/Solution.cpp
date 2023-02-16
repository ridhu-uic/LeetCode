// https://leetcode.com/problems/maximum-product-subarray

class Solution {
public:
    int maxProduct(vector<int>& nums) {

        int maxProduct=nums[0];
        int minProduct=nums[0];
        int result=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            int curr=nums[i];
             int temp=max(curr,max(maxProduct*nums[i],minProduct*nums[i]));
             minProduct=min(curr,min(maxProduct*nums[i],minProduct*nums[i]));
            maxProduct=temp;
            result=max(maxProduct,result);

        }
        
        return result;
        
    }
};