// https://leetcode.com/problems/maximum-product-subarray

class Solution {
public:
    int maxProduct(vector<int>& nums) {

        int product=1;
        int maxProduct=nums[0];
        for(int i=0;i<nums.size();i++)
        {
                product=nums[i];
                if(product>maxProduct)
                    maxProduct=product;
            for(int j=i+1;j<nums.size();j++)
            {

                product=product*nums[j];
                if(product>maxProduct)
                    maxProduct=product;
            }
        }
        
        return maxProduct;
        
    }
};