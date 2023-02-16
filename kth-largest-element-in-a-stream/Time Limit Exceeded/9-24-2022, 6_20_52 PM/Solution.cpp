// https://leetcode.com/problems/kth-largest-element-in-a-stream

class KthLargest {
public:
    int n;
    priority_queue <int> q;
    KthLargest(int k, vector<int>& nums) {
        n=k;
        for(int i=0;i<nums.size();i++)
            q.push(nums[i]);
    }
    
    int add(int val) {

        q.push(val);
        vector <int> temp;
        for(int i=0;i<n-1;i++)
        {
            temp.push_back(q.top());
            q.pop();
        }
        val=q.top();
        for(int i=0;i<n-1;i++)
        {
            q.push(temp[i]);
        }
        return val;
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */