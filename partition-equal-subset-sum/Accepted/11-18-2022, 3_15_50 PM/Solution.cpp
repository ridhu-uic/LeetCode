// https://leetcode.com/problems/partition-equal-subset-sum

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum=0;
        
        const int n=nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++)
            sum=sum+nums[i];

        if(sum%2==1 )
            return false;
        int x=sum/2;
        vector<vector <bool>> dp;
        dp.resize(n+1,vector<bool>(x+1));
        for(int i=0;i<=n;i++)
        {
            dp[i][0]=true;
        }
        for(int i=1;i<=x;i++)
            dp[0][i]=false;
        for(int i=1;i<=n;i++)       //nums[i] is the item
        {
            for(int j=1;j<=x;j++)
            {
                if(j<nums[i-1])
                    dp[i][j]=dp[i-1][j];
                else
                    dp[i][j]=dp[i-1][j] || dp[i-1][j-nums[i-1]];
            }
         }
        return dp[n][x];
    }
};