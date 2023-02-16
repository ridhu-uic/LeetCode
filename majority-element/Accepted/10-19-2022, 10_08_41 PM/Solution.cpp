// https://leetcode.com/problems/majority-element

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count=1;
        int result=nums[0];
        int size=nums.size();
        for(int i=1;i<size;i++)
        {
            if(count==0)
                {
                    result=nums[i];
                    count=1;
                    continue;
                }
            if(nums[i]!=result)
                count--;
            else
                count++;

            
        }
        return result;
    }
};