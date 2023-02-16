// https://leetcode.com/problems/container-with-most-water

class Solution {
public:
    int maxArea(vector<int>& height) {

        int n=height.size();
        int water=0;
        if(n==1)
            return 0;
        int l=0;
        int h=n-1;

        while(l<h)
        {
            water=max(water,min(height[l],height[h])*(h-l));
            if(height[l]<height[h])
                l++;
            else
                h--;
        }

        return water;

        
    }
};