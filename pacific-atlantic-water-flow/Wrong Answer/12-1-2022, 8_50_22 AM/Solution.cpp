// https://leetcode.com/problems/pacific-atlantic-water-flow

class Solution {
    vector<vector<int>> pacific;
    vector<vector<int>> atlantic;
    vector <vector<int>> visited;
    vector <vector <int>> result;
    int nr,nc;
public:
    void exploreIsland(int r,int c,vector<vector<int>>& heights)
    {
        queue <int> qr;
        queue <int> qc;

        qr.push(r);
        qc.push(c);

        while(!qr.empty())
        {
            int rr=qr.front();
            int cc=qc.front();

            int dr[4]={+1,-1,0,0};
            int dc[4]={0,0,+1,-1};

            for(int i=0;i<4;i++)
            {
                int tr=rr+dr[i];
                int tc=cc+dc[i];

                if(tr<0 || tr>=nr)
                    continue;
                if(tc<0 || tc>=nc)
                    continue;

                if(visited[tr][tc]==0)
                {
                   visited[tr][tc]=1;
                   qr.push(tr);
                   qc.push(tc);
                }
                
            }
            

        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        nr=heights.size();
        nc=heights.size();

        

        visited.resize(nr,vector <int> (nc,0));
        pacific.resize(nr,vector <int> (nc,0));
        atlantic.resize(nr,vector <int> (nc,0));

        vector <int> tr;
        tr.push_back(0);
        tr.push_back(nc-1);
        result.push_back(tr);
        vector <int> tc;
        tc.push_back(nr-1);
        tc.push_back(0);
        result.push_back(tc);

        for(int i=0;i<nc;i++)
            {
                pacific[0][i]=1;
                atlantic[nr-1][i]=1;
            }

        for(int i=0;i<nr;i++)
            {
                pacific[i][0]=1;
                atlantic[i][nc-1]=1;
            }

        for(int i=1;i<nr;i++)
        {
            for(int j=1;j<nc;j++)
            {
                if((pacific[i-1][j]==1 && heights[i-1][j]<=heights[i][j])  | (pacific[i][j-1]==1 && heights[i][j-1]<=heights[i][j]) )
                {
                    pacific[i][j]=1;
                }
            }
        }



        for(int i=nr-2;i>=0;i--)
        {
            for(int j=nc-2;j>=0;j--)
            {
                if((atlantic[i+1][j]==1 && heights[i+1][j]<=heights[i][j]) | (atlantic[i][j+1]==1 && heights[i][j+1]<=heights[i][j]))
                {
                    atlantic[i][j]=1;
                    if(pacific[i][j]==1)
                    {
                        vector <int> temp;
                        temp.push_back(i);
                        temp.push_back(j);
                        result.push_back(temp);
                    }
                }
            }
        }


        for(int i=1;i<nc;i++)
            {
                
                if(pacific[nr-1][i]==1 && atlantic[nr-1][i]==1)
                {
                        vector <int> temp;
                        temp.push_back(nr-1);
                        temp.push_back(i);
                        result.push_back(temp);

                }
            }

        for(int i=1;i<nr;i++)
            {
             
                if(pacific[i][nr-1]==1 && atlantic[i][nr-1]==1)
                {
                        vector <int> temp;
                        temp.push_back(i);
                        temp.push_back(nc-1);
                        
                        result.push_back(temp);

                }

            }
        return result;
    }
};