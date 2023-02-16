// https://leetcode.com/problems/kth-largest-element-in-a-stream

class KthLargest {
public:
    int n;
    vector <int> heap;
    KthLargest(int k, vector<int>& nums) {
        n=k;
        heap=nums;
        make_heap(heap.begin(),heap.end()) ;


    }
    
    int add(int val) {

        heap.push_back(val);
        push_heap(heap.begin(),heap.end());
        make_heap(heap.begin(),heap.end()) ;
        for(int i=0;i<n;i++)
        {
            val=heap.front();
            cout<<val<<" ";
            pop_heap(heap.begin(),heap.end()-i);    
        }
        cout<<endl;
        return val;
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */