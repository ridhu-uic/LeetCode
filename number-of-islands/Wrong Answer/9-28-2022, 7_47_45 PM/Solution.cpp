// https://leetcode.com/problems/number-of-islands

class Solution {
public:
    void explore(vector<vector<char>>& grid,vector <vector<bool>> &visited,int r,int c)
    {
        visited[r][c]=true;
        int dr[4]={1,-1,0,0};
        int dc[4]={0,0,1,-1};
        int m=grid.size();
        int n=grid[0].size(); 
        int rr,cc;
        
        for(int i=0;i<4;i++)
        {
            rr=r+dr[i];
            cc=c+dc[i];
            
            if(!(rr>0 && rr<m & cc>0 & cc<n))
                continue;
            if(visited[r][c]==true)
                continue;
            if(grid[r][c]=='1')
                explore(grid,visited,rr,cc);
            else
                visited[rr][cc]='1';
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
    
        int count=0;
        int m=grid.size();
        int n=grid[0].size(); 
            
            
        vector <vector<bool>> visited;
        visited.resize(m);
        for(int i=0;i<m;i++)
            visited[i].resize(n);
    
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                visited[i][j]=0;
            }
        }
    
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(visited[i][j])
                    continue;
                if(grid[i][j]=='0')
                {
                    visited[i][j]=true;
                    continue;
                }
                explore(grid,visited,i,j);
                count=count+1;
                
            }
        }
        
    return count;
    }
};