// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
            int profit=0;
            int hold=-prices[0];
            for (int i=1;i<prices.size();i++)
            {
                profit=max(profit,hold+prices[i]-fee);
                hold=max(hold,profit-prices[i]);
            }

        return profit;

    }
};