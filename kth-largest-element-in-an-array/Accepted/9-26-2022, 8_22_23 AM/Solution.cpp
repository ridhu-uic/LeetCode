// https://leetcode.com/problems/kth-largest-element-in-an-array

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue <int> p_queue(nums.begin(),nums.end());
        for(int i=0;i<k-1;i++)
        {
            p_queue.pop();
            }
        return p_queue.top();
    }
};