// https://leetcode.com/problems/kth-largest-element-in-a-stream

class KthLargest {
public:
    int n;
    priority_queue <int> q;
    priority_queue <int,vector<int>,greater<int>> q1;
    KthLargest(int k, vector<int>& nums) {
        n=k;
        for(int i=0;i<nums.size();i++)
        {
            q.push(nums[i]);
            q1.push(nums[i]);
        }
    }
    
    int add(int val) {

        q.push(val);
        q1.push(val);
        vector <int> temp;
        if(n<=q.size()/2)
        {
            cout<<"inside loop 1"<<endl;
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
        }
        else{
             cout<<"inside loop 2"<<endl;
            int temp_size=q1.size();
            for(int i=0;i<temp_size-n;i++)
            {
                temp.push_back(q1.top());
                q1.pop();
            }
            val=q1.top();
            for(int i=0;i<temp_size-n;i++)
            {
                q1.push(temp[i]);
            }
        }
        return val;
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */