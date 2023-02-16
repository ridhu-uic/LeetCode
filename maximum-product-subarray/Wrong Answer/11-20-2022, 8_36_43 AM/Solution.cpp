// https://leetcode.com/problems/maximum-product-subarray

class Solution {
public:
    int maxProduct(vector<int>& nums) {

        int product=1;
        int maxProduct=0;
        for(int i=0;i<nums.size();i++)
        {
                product=nums[i];
            for(int j=i+1;j<nums.size();j++)
            {
                if(product>maxProduct)
                    maxProduct=product;
                product=product*nums[j];
            }
        }
        
        return maxProduct;
        
    }
};