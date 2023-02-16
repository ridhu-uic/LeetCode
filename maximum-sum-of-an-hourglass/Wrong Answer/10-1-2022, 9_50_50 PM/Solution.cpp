// https://leetcode.com/problems/maximum-sum-of-an-hourglass

class Solution {
public:
    int hourGlassSum(int r,int c,vector<vector<int>>& grid)
    {
        int sum=0;
        int hourglass[3][3]={{1,1,1},{0,1,0},{1,1,1}};
        
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                sum=sum+(hourglass[i][j]*grid[r+i][c+j]);
            }
        }
        cout<<"Sum "<<sum<<endl;
        return sum;
    }
    
    int maxSum(vector<vector<int>>& grid) {

        int sum=0;
        int maxSum=INT_MIN;
        for(int i=0;i<grid.size()-3;i++)
        {
            for(int j=0;j<grid[i].size()-3;j++)
            {
                sum=hourGlassSum(i,j,grid);
                if(sum>maxSum)
                    maxSum=sum;
            }
        }
        return maxSum;
    }
};