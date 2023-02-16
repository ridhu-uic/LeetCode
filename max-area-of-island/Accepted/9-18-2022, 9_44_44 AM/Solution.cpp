// https://leetcode.com/problems/max-area-of-island

class Solution {
public:
    
    int areaofIsland(vector<vector<int>>& grid,int i,int j,vector<vector<int>>& visited)
    {
        int dr[4]={-1,1,0,0};
        int dc[4]={0,0,-1,1};
        
        visited[i][j]=1;
        int area =1;
        
        for(int k=0;k<4;k++)
        {
            int r=i+dr[k];
            int c=j+dc[k];
            
            if(r<0 or r>=grid.size() or c<0 or c>=grid[0].size())
                continue;
            
            if(visited[r][c])
                continue;
            if(grid[r][c]==0)
            {
                visited[r][c]=0;
                continue;
            }
            
            area=area+areaofIsland(grid,r,c,visited);
            
        }
        return area;
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        vector<vector<int>> visited;
        int m=grid.size();
        int n=grid[0].size();
        int area=0;
        int maxarea=0;
        cout<<m<<" "<<n<<endl;
        visited.resize(grid.size(),vector <int> (grid[0].size()));
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                visited[i][j]=0;
            }
        }
        
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(visited[i][j]==1)
                    continue;
                
                if(grid[i][j]==0)
                {
                    visited[i][j]=1;
                    continue;
                }
                
                area=areaofIsland(grid,i,j,visited);
                if(maxarea<area)
                    maxarea=area;                
            }
        }
        
        return maxarea;
    }
};