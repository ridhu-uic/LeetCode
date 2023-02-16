// https://leetcode.com/problems/coin-change-ii

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector <vector<int>> dp;
        int n=coins.size();
        dp.resize(n+1,vector <int> (amount+1));

        dp[0][0]=1;

        for(int i=1;i<amount+1;i++)
            dp[0][i]=0;

        for(int i=1;i<n+1;i++)
        {
            for(int j=0;j<amount+1;j++)
            {
                if(j==0)
                    dp[i][j]=1;

                if(j-coins[i-1]>=0)
                    dp[i][j]=dp[i][j-coins[i-1]]+dp[i-1][j];
                else    
                    dp[i][j]=dp[i-1][j];
                
            }
        }




        return dp[n][amount];

    }
};