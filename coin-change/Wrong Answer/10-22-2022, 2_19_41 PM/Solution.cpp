// https://leetcode.com/problems/coin-change

class Solution {
public:
    int minCoins(vector<int>& coins, int amount,vector<int>&no_of_coins )
    {
        if(amount<0)
            return INT_MAX;
        if(no_of_coins[amount]!=INT_MAX)
            return no_of_coins[amount];
        for(int i=0;i<coins.size();i++)
        {
            if(amount==coins[i])
                return no_of_coins[amount]=1;
        }
        int temp_coins;
        for(int i=0;i<coins.size();i++)
        {
            temp_coins=minCoins(coins,amount-coins[i],no_of_coins);
            //cout<<"amount "<<amount<<"   "<<"coin "<<coins[i]<<"  "<<temp_coins<<endl;
            if(temp_coins==INT_MAX)
                continue;
            temp_coins=temp_coins+1;
            if(temp_coins<no_of_coins[amount])
                no_of_coins[amount]=temp_coins;
        }

    return no_of_coins[amount];
        
    }
    
    int coinChange(vector<int>& coins, int amount) {
        int sum=0;
        if(amount==0)
            return 0;
        for(int i=coins.size()-1;i>=0;i--)
        {
            if(coins[i]>amount)
                continue;
            int x=amount/coins[i];
            amount=amount%coins[i];
            cout<<"amount  :"<<amount<<endl;
            sum=sum+x;
            if(amount==0)
                return sum;
        }
        return -1;
    }
};