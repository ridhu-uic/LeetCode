// https://leetcode.com/problems/kth-largest-element-in-a-stream

class KthLargest {
public:
    vector <int> test;
    int k;
    KthLargest(int k, vector<int>& nums) {
        test=nums;
        this->k=k;
    }
    
    int add(int val) {
        test.push_back(val);
        priority_queue <int> p_queue_temp(test.begin(),test.end());

        for(int i=1;i<k;i++)
        {   
            cout<<p_queue_temp.top();
            p_queue_temp.pop();
        }
        
        return p_queue_temp.top();

    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */