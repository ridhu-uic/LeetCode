// https://leetcode.com/problems/partition-equal-subset-sum

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum=0;
        int subsum=0;
        const int n=nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++)
            sum=sum+nums[i];

        if(sum%2==1 )
            return false;

        vector<vector <int>> dp;
        dp.resize(n,vector<int>(sum/2+1));

        for(int i=0;i<n;i++)       // item
        {
            for(int j=0;j<sum/2+1;j++)
            {
                if(j==0)
                    {
                        dp[i][j]=0;
                        continue;
                    }
                else if(j<nums[i])
                    dp[i][j]=dp[i-1][j];
                else if(j==nums[i])
                    {
                        dp[i][j]=1;
                    }
                else
                {
                    dp[i][j]=dp[i][j-nums[i]];
                }
            }
        }



        return dp[n-1][sum/2];
    }
};