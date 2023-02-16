// https://leetcode.com/problems/max-area-of-island

class Solution {
vector <vector<int>> visited;
int nr,nc;
    int exploreIsland(int r,int c,vector<vector<int>>& grid)
    {
        int area=1;
        queue <int> qr;
        queue <int> qc;
        int dr[4]={+1,-1,0,0};
        int dc[4]={0,0,+1,-1};

        qr.push(r);
        qc.push(c);

        while(!qr.empty())
        {
            int rr=qr.front();
            int cc=qc.front();
            qr.pop();
            qc.pop();

            for(int i=0;i<4;i++)
            {
                int ar=rr+dr[i];
                int ac=cc+dc[i];

                if(ar<0 || ar>=nr)
                    continue;

                if(ac<0 || ac>=nc)
                    continue;

                if(visited[ar][ac]==0 && grid[ar][ac]==1)
                {
                    visited[ar][ac]=1;
                    qr.push(ar);
                    qc.push(ac);
                    area++;
                }

                
            }
        }
        return area;
    }

public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        nr=grid.size();
        nc=grid[0].size();
        visited.resize(nr, vector <int> (nc,0));
        int maxarea=0;
        for(int i=0;i<nr;i++)
        {
            for(int j=0;j<nc;j++)
            {
                if(visited[i][j]==0 && grid[i][j]==1)
                {
                    visited[i][j]=1;
                    int area=exploreIsland(i,j,grid);
                    if(area>maxarea)
                        maxarea=area;
                }
            }
        }
        return maxarea;
    }
};