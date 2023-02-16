// https://leetcode.com/problems/container-with-most-water

class Solution {
public:
    int maxArea(vector<int>& height) {
        
        int first=0;
        int last=height.size()-1;
        int area=0;
        int max=0;
        
        
        while(first<last)
        {
            
            area=(last-first)*min(height[last],height[first]);
            
            if (max<area)
                max=area;
            
            if(height[last]<=height[first])
            {
                last--;
            }
            else
                first++;
            
            
        }
        
        
        return max;
 
        
        
        
        }
                
};