// https://leetcode.com/problems/surrounded-regions

class Solution {
public:

    bool dfs(vector<vector<char>>& board,vector<vector<bool>>& visited,int r,int c,bool flag,queue <int> &qr,queue <int> &qc)
    {
        visited[r][c]=true;
        qr.push(r);
        qc.push(c);
        int m=board.size();
        int n=board[0].size();

        int dr[4]={1,-1,0,0};
        int dc[4]={0,0,1,-1};

        int rr,cc;
        for(int i=0;i<4;i++)
        {
            rr=r+dr[i];
            cc=c+dc[i];
            

            if(rr<0 || rr>=m || cc<0 || cc>=n)
            {
                flag=false;
                continue;
            }
            if(visited[rr][cc]==true)
                continue;

            if(board[rr][cc]=='O')
            {
                flag=flag*dfs(board,visited,rr,cc,flag,qr,qc);
            }
            else
            {
                visited[rr][cc]=true;
            }

        }


        return flag;
    }
    void solve(vector<vector<char>>& board) {
        int m=board.size();
        int n=board[0].size();

        vector<vector<bool>> visited;
        visited.resize(m,vector<bool>(n));

        bool flag_unsurrounded=true;
        queue <int> qr;
        queue <int> qc;

        int rr,cc;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(visited[i][j]==false && board[i][j]=='X')
                    {

                        visited[i][j]=true;
                        continue;
                    }

                
                
                if(visited[i][j]==false && board[i][j]=='O')
                    {

                    flag_unsurrounded=dfs(board,visited,i,j,flag_unsurrounded,qr,qc);
                    if(flag_unsurrounded)
                        {
                            while(!qr.empty())
                            {
                                rr=qr.front();
                                cc=qc.front();
                                board[rr][cc]='X';
                                qr.pop();
                                qc.pop();
                            }
                            
                            
                        }
                    }
                
            }
        }
    }
};