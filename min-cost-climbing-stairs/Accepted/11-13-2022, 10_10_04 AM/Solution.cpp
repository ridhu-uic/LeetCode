// https://leetcode.com/problems/min-cost-climbing-stairs

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        cost.push_back(0);
        int  price[n+2];
        
        price[0]=0;
        price[1]=cost[0];
        //cout<<cost[cost.size()]<<"ending"<<endl;
        for(int i =2;i<=n+1;i++)
        {
        price[i]=cost[i-1]+min(price[i-1],price[i-2]);
        cout<<"hello    :"<<price[i]<<endl;
        }
        return price[n+1];
    }
};