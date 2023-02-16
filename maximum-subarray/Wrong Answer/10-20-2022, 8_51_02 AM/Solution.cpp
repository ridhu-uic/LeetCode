// https://leetcode.com/problems/maximum-subarray

class Solution {
public:
    int max3(int a,int b,int c)
    {
        if(a>b && a>c)
            return a;
        if(b>c)
            return b;
        return c;
    }
    int maxCrossSum(vector<int>& nums,int l,int mid,int h)
    {
        long leftSum=INT_MIN;
        long rightSum=INT_MIN;
        long sum=0;
        for(int i=l;i<mid;i++)
        {
            sum=sum+nums[i];
            if(sum>leftSum)
                leftSum=sum;
        }
        sum=0;
        for(int i=mid;i<=h;i++)
        {
            sum=sum+nums[i];
            if(sum>rightSum)
                rightSum=sum;
        }
        return max3(leftSum,rightSum,rightSum+leftSum);
    }
    int maxSubArray1(vector<int>& nums,int l,int h)
    {
        if(l>h)
            return INT_MIN;
        if(l==h)
            return nums[l];
        int mid=(l+h)/2;
        return max3(maxSubArray1(nums,l,mid-1),maxSubArray1(nums,mid+1,h),maxCrossSum(nums,l,mid,h));
    }
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        int l=0;
        int h=n-1;

     return maxSubArray1(nums,  l, h);   
    }
};