// https://leetcode.com/problems/find-pivot-index

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
     int low=0;
     int high=nums.size()-1;
     int leftsum=nums[low];
     int rightsum=nums[high];
     while(low<high)
     {
            if(leftsum>rightsum)
                {
                    high--;
                    rightsum=rightsum+nums[high];
                }
            else if(rightsum>leftsum)
            {
                low++;
                leftsum=leftsum+nums[low];
            }
            else
            {
                high--;
                rightsum=rightsum+nums[high];

                low++;
                leftsum=leftsum+nums[low];

            }
     }
     if(leftsum==rightsum && low==high)
        return low;
    
    return -1;

    }
};