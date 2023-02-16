// https://leetcode.com/problems/find-peak-element

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
    
     int peakindex=0;
     int n=nums.size();
     if(n==1)
        return 0;
     if(nums[0]<nums[1])
        peakindex=0;
    for(int i=1;i<n-1;i++)  
    {
        if(nums[i-1]<nums[i] && nums[i+1]<nums[i])
            peakindex=i;
    }
     if(nums[n-2]<nums[n-1])
        peakindex=n-1;
    return peakindex;
    }
};