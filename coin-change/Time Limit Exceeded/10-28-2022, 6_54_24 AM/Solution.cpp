// https://leetcode.com/problems/coin-change

class Solution {
public:
    int minCoins(vector<int>& coins, int amount,vector<int>&no_of_coins, int maxValue )
    {
        if(amount<0)
            return maxValue;
        
        if(no_of_coins[amount]!=maxValue)
            return no_of_coins[amount];


        for(int i=0;i<coins.size();i++)
        {
            no_of_coins[amount]=min(no_of_coins[amount],minCoins(coins,amount-coins[i],no_of_coins,maxValue)+1);
        }

    return no_of_coins[amount];
        
    }
    
    int coinChange(vector<int>& coins, int amount) {
     vector<int> no_of_coins(amount+1,amount+1);
     no_of_coins[0]=0;
    for(int i=0;i<coins.size();i++)
    {
      if(coins[i]<amount+1)
        no_of_coins[coins[i]]=1;
    }
     int coins1= minCoins(coins,amount,no_of_coins,amount+1);
     for(int i=0;i<amount+1;i++)
      cout<<" coin required for  "<<i<<"  "<<no_of_coins[i]<<endl;
     if(coins1==amount+1)
        return -1;
    return coins1;

    }
};