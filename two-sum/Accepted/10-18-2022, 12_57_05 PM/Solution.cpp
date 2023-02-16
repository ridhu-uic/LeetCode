// https://leetcode.com/problems/two-sum

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(nums[j]==(target-nums[i]))
                {
                    cout<<i<<j<<endl;
                    vector <int> x;
                    x.push_back(i);
                    x.push_back(j);
                    return x;

                }
            }
        }
        return vector <int> ();
    }
};