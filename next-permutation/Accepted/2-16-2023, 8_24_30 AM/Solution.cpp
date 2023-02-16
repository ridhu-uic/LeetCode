// https://leetcode.com/problems/next-permutation

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        
        int i=nums.size()-1;
        int n=nums.size();
        
        while(i>0 && nums[i-1]>=nums[i])
        {
            i--;
            }
        
        cout<<"i = "<<i<<endl;

        sort(nums.begin()+i,nums.end());

        
        if(i!=0)
        {
            int numsi=nums[i];
            int numsi1=nums[i-1];
            
            int k;
            for (k=i;k<n-1;k++)
            {
                if(nums[k]>numsi1)
                {
                    break;
                }
            }
            
            nums[i-1]=nums[k];
            nums[k]=numsi1;
        
        
        }
        
    }
};