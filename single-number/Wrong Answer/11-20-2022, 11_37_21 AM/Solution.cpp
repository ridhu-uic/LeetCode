// https://leetcode.com/problems/single-number

class Solution {
public:
    int singleNumber(vector<int>& nums) {
     int single=nums[0];
    int i=1;
     while(i<nums.size())
     {
         if(single==nums[i])
            {
            single=nums[i+1];
            i++;
            }
            i++;
     }
    return single;
    }
};