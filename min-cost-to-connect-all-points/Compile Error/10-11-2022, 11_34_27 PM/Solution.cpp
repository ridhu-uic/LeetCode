// https://leetcode.com/problems/min-cost-to-connect-all-points

class Solution {

public:

int minimumCost(vector<int>& cost) {

priority_queue <int> p_q(cost.begin(),cost.end());

int purchase_cost=0;

//int n=cost.size();

int count=1;

while(!p_q.empty())

{

//cout<<p_q.top()<<endl;

if(count%3!=0)

purchase_cost=purchase_cost+p_q.top();

p_q.pop();

count++;

}

return purchase_cost;

}

};