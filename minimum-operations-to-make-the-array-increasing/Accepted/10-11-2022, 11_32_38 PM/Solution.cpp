// https://leetcode.com/problems/minimum-operations-to-make-the-array-increasing

class Solution {
public:
    int minOperations(vector<int>& nums) {
    int count=0;
    int n=nums.size();

    int temp_n=n;
    for(int i=1;i<n;i++)
    {
        /*while(nums[i]<=nums[i-1])
        {
            nums[i]++;
            count++;
        }*/

        if(nums[i]<=nums[i-1])
        {
            count=count+nums[i-1]-nums[i]+1;
            nums[i]=nums[i-1]+1;
        }

    }

    return count;
    }
};
