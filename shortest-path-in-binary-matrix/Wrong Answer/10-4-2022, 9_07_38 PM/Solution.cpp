// https://leetcode.com/problems/shortest-path-in-binary-matrix

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        vector<vector<bool>> visited;
        int m=grid.size();
        int n=grid[0].size();
        if(grid[0][0]==1 || grid[m-1][n-1]==1)
            return -1;

        visited.resize(m,vector<bool>(n,false));
        int count=1;
        int dr[8]={1,-1,0,0,1,1,-1,-1};
        int dc[8]={0,0,1,-1,1,-1,1,-1};

        queue <int> qr;
        queue <int> qc;

        
        qr.push(0);
        qc.push(0);

        visited[0][0]=true;

        int c_r,c_c;
        int rr,cc;
        int elements_in_current_level=1;
        int elements_in_next_level=0;
        //int count=0;
        while(!qr.empty())
        {
            c_r=qr.front();
            c_c=qc.front();

            cout<<"Under Queue :"<<c_r<<"  ,"<<c_c<<endl;
            int flag=0;
            qr.pop();
            qc.pop();
            
            elements_in_current_level--;

            for(int i=0;i<8;i++)
            {
                rr=c_r+dr[i];
                cc=c_c+dc[i];

                //cout<<"     Under Loop  :"<<rr<<"   "<<cc<<endl;
                if(rr==m || rr==-1 || cc==n || cc==-1)
                    continue;

                if(visited[rr][cc])
                    continue;

                cout<<"         Loop Continue : "<<rr<<","<<cc<<endl;
                visited[rr][cc]=true;

                if(grid[rr][cc]==0)
                {
                    elements_in_next_level++;
                    qr.push(rr);
                    qc.push(cc);
                    if(flag==0)
                        {
                            cout<<"         "<<rr<<"    "<<cc<<endl;
                            count=count+1;
                            flag=1;
                        }
                }

                if(rr==m-1 && cc==n-1)
                    return count;

            }
            if(elements_in_current_level==0)
            {
                elements_in_current_level=elements_in_next_level;
                elements_in_next_level=0;
                flag=0;
            }
            
        }

        return -1;
    }
};