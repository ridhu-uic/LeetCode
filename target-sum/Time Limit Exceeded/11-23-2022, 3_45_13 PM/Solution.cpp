// https://leetcode.com/problems/target-sum

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int total=accumulate(nums.begin(),nums.end(),0);
        int n=nums.size();
        if(total<target || target<-total)
            return 0;
        
        vector<vector<int>> dp;
        dp.resize(n+1,vector <int> (2*total+1,0));
        for(int i=0;i<(2*total+1);i++)
            dp[0][i]=0;
        dp[0][total]=1;

        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<(2*total+1);j++)
            {
               
                if(j+nums[i-1]<(2*total+1))
                    {
                        dp[i][j]=dp[i-1][j+nums[i-1]];
                    }

                if(j-nums[i-1]>=0)
                    {
                    dp[i][j]+=dp[i-1][j-nums[i-1]];

                    }

                cout<<"i = :"<<i<<"j = : "<<j<<"  ,dp[i][j]   :"<<dp[i][j]<<endl;

            }
        }
        return dp[n][target+total];
    }
 
};