// https://leetcode.com/problems/last-stone-weight

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue <int> p_queue;
        int n=stones.size();
        for(int i=0;i<n;i++)
            p_queue.push(stones[i]);
        int a1,a2;
        while(p_queue.size()>1)
        {
            a1=p_queue.top();
            p_queue.pop();
            a2=p_queue.top();
            p_queue.pop();
            
            p_queue.push(abs(a1-a2));
        }
        
        return p_queue.top();
    }
};