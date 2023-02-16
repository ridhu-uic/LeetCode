// https://leetcode.com/problems/3sum

class Solution {
public:
    //int find_element(int x)
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        int temp;
        int l;
        int h;
        set <vector<int>> s;
        vector<vector<int>> result;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++)
        {
            temp=-nums[i];
            l=i+1;
            h=n-1;
            while(l<h)
            {

                if(nums[l]+nums[h]<temp)
                    l++;
                else if(nums[l]+nums[h]>temp)
                    h--;
                else
                {
                    vector <int> x(3);
                    x[0]=nums[i];x[1]=nums[l];x[2]=nums[h];
                    s.insert(x);
                    l++;
                    h--;
                }
            }
           
        }
        for(auto p : s)
            result.push_back(p);
        return result;
    }
      
};