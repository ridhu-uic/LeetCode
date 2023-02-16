// https://leetcode.com/problems/number-of-islands

class Solution {
public:
    void explore(vector<vector<char>>& grid,vector <vector<bool>> &visited,int r,int c)
    {
        int dr[4]={1,-1,0,0};  //{up,down,right,left}
        int dc[4]={0,0,1,-1};
        int m=grid.size();
        int n=grid[0].size(); 
        int rr,cc;

        for(int i=0;i<4;i++)
        {
            rr=r+dr[i];
            cc=c+dc[i];
            
            if(rr<0)
                continue;
            if(cc<0)
                continue;
            if(rr>=m)
                continue;
            if(cc>=n)
                continue;
            
            if(visited[rr][cc]==true)
                continue;
            if(grid[rr][cc]=='0')
            {
                visited[rr][cc]=true;
                continue;
            }
            cout<<"rr  :"<<rr <<"cc  :"<<cc<<endl; 
            visited[rr][cc]=true;
            explore(grid,visited,rr,cc);         
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
    
        cout<<"m   :"<<m<<"n   :"<<n<<endl;
        
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
                if(visited[i][j]==false && grid[i][j]=='1')
                {

                    cout<<"i  :"<<i <<"j  :"<<j<<endl; 
                    explore(grid,visited,i,j);
                    count=count+1;
                    continue;

                }

                cout<<"i again  :"<<i <<"j again  :"<<j<<endl; 
            }
        }
        
    return count;
    }
};