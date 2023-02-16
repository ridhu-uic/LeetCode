// https://leetcode.com/problems/coin-change

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {

     int array[amount+1];
     array[0]=0;

    for(int i=1;i<=amount;i++)
    {
        int current_coin[coins.size()];
        int min=INT_MAX-1;
        for(int j=0;j<coins.size();j++)
        {
            if(i-coins[j]>=0)
            {
                current_coin[j]=1+array[i-coins[j]];
                if(current_coin[j]<min)
                    min=current_coin[j];
            }
            else
            {
                current_coin[j]=INT_MAX-1;
            }
            array[i]=min;
        }
    }
    if(array[amount]>=INT_MAX-1)
        return -1;
     return array[amount];

    }
};