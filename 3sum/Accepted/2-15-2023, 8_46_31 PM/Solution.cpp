// https://leetcode.com/problems/3sum

class Solution {
public:
    //int find_element(int x)
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        vector <vector<int>> v;
        vector <int> n;
        
        sort(nums.begin(),nums.end());
        for (int i=0;i<nums.size() && nums[i]<=0;i++)
        {
            if (i == 0 || nums[i - 1] != nums[i]) {
                
                int l=i+1;
                int r=nums.size()-1;
                int sum=-nums[i];

                while(l<r)
                {
                    if(nums[l]+nums[r]==sum)
                    {   
                        v.push_back({nums[i],nums[l++],nums[r--]});
                            
                        while (l < r && (nums[l] == nums[l - 1]))
                            l++;

                        
                    }
                    
                    else if(nums[l]+nums[r]<sum)
                        
                    {
                        l++;
                        
                    }
                    
                    else
                    {
                        r--;
                    }

                }

            
            }
        
        
        
        }
        
        
        
        
        return v;
        
        
        
    }
      
};