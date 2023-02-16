// https://leetcode.com/problems/min-cost-climbing-stairs

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        cost.push_back(0);
        int n=cost.size();

        vector<int>min_cost;
        min_cost.resize(n,0);

        min_cost[0]=cost[0];
        min_cost[1]=cost[1];
        cout<<min_cost[0]<<"  "<<min_cost[1]<<endl;
        for(int i=2;i<n;i++){
            min_cost[i]=min(cost[i]+min_cost[i-1],cost[i]+min_cost[i-2]);
            cout<<min_cost[i]<<endl;
        }

        return min_cost[n-1];
    }
};