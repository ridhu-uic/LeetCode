// https://leetcode.com/problems/coin-change

class Solution {
public:
    int minCoins(vector<int>& coins, int amount,vector<int>&no_of_coins )
    {
        if(amount<0)
            return INT_MAX;
        
        if(no_of_coins[amount]!=INT_MAX)
            return no_of_coins[amount];


        int temp_coins;
        for(int i=0;i<coins.size();i++)
        {
            temp_coins=minCoins(coins,amount-coins[i],no_of_coins);
            if(temp_coins==INT_MAX)
                continue;
            temp_coins=temp_coins+1;
            if(temp_coins<no_of_coins[amount])
                no_of_coins[amount]=temp_coins;
        }

    return no_of_coins[amount];
        
    }
    
    int coinChange(vector<int>& coins, int amount) {
     vector<int> no_of_coins(amount+1,INT_MAX);
     no_of_coins[0]=0;
    for(int i=0;i<coins.size();i++)
    {
      if(coins[i]<amount+1)
        no_of_coins[coins[i]]=1;
    }
     int coins1= minCoins(coins,amount,no_of_coins);
     if(coins1==INT_MAX)
        return -1;
    return coins1;

    }
};