// https://leetcode.com/problems/target-sum

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int total = 0;
        for(int x: nums)
            total += x;
        if (abs(target) > total || (total + target) % 2 != 0){ 
            return 0;
        }
        int avg = (total + target)/2;
        int res = sCount(nums,avg);
        return res;
    }
    
    int sCount(vector<int>& nums, int s1){
        int n = nums.size();
        int dpt[n+1][s1+1];
        dpt[0][0] = 1;
        for(int i=1;i<s1+1;i++)
            dpt[0][i] = 0;
        for(int i=1;i<n+1;i++)
            for(int j=0;j<s1+1;j++){
                if(nums[i-1] > j)
                    dpt[i][j] = dpt[i-1][j];
                else
                    dpt[i][j] = dpt[i-1][j] + dpt[i-1][j-nums[i-1]];
            }
        
        return dpt[n][s1];
    }
};