// https://leetcode.com/problems/number-of-islands

class Solution {
    vector<vector<int>> visited;
    int nr,nc;
public:
    void exploreIsland(int r,int c, vector<vector<char>>& grid)
    {
        //cout<<endl<<grid[r][c]<<visited[r][c]<<endl;
        queue <int> qr;
        queue <int> qc;

        int dr[4]={+1,-1,0,0};
        int dc[4]={0,0,+1,-1};
        //cout<<"here";
        qr.push(r);
        qc.push(c);

        while(!qr.empty())
        {
            int rr=qr.front();
            qr.pop();
            int cc=qc.front();
            qc.pop();
            visited[rr][cc]=1;
            //cout<<"queue"<<rr<<cc<<endl;
            for(int i=0;i<4;i++)
            {
                int tempr=rr+dr[i];
                int tempc=cc+dc[i];
                //cout<<"loop"<<tempr<<tempc<<endl;
                if(tempr<0 || tempr>=nr)
                    continue;

                if(tempc<0 || tempc>=nc)
                    continue;

                //cout<<"loop"<<tempr<<tempc<<endl;
                if(visited[tempr][tempc]==0 && grid[tempr][tempc]=='1')
                {
                    qr.push(tempr);
                    qc.push(tempc);
                }


            }
        }





    }
    
    int numIslands(vector<vector<char>>& grid) {
            nr=grid.size();
            nc=grid[0].size();
            visited.resize(nr,vector <int> (nc,0) );

            int count=0;

            for(int i=0;i<nr;i++)
            {
                for (int j=0;j<nc;j++)
                {
                    if(grid[i][j]=='1' && visited[i][j]==0)
                    {
                        //cout<<grid[i][j]<<visited[i][j];
                        exploreIsland(i,j,grid);
                        count++;
                    }
                }
            }


            return count;
            



        
    }
};