// https://leetcode.com/problems/pacific-atlantic-water-flow

class Solution {
    vector<vector<int>> pacific;
    vector<vector<int>> atlantic;
    vector <vector<int>> visited;
    vector <vector <int>> result;
    int nr,nc;
public:
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        nr=heights.size();
        nc=heights[0].size();

        set <vector<int>> sresult;

        visited.resize(nr,vector <int> (nc,0));
        pacific.resize(nr,vector <int> (nc,0));
        atlantic.resize(nr,vector <int> (nc,0));

        vector <int> tr;
        tr.push_back(0);
        tr.push_back(nc-1);
        sresult.insert(tr);
        vector <int> tc;
        tc.push_back(nr-1);
        tc.push_back(0);
        sresult.insert(tc);

        for(int i=0;i<nc;i++)
            {
                pacific[0][i]=1;
                if(nr-1>=0)
                atlantic[nr-1][i]=1;
            }

        for(int i=0;i<nr;i++)
            {
                pacific[i][0]=1;
                if(nc-1>=0)
                atlantic[i][nc-1]=1;
            }

            cout<<"done 1";

        for(int i=1;i<nr;i++)
        {
            for(int j=1;j<nc;j++)
            {
                cout<<endl<<endl;
                cout<<i<<"  "<<j<<endl;
                cout<<pacific[i-1][j]<<endl;
                cout<<pacific[i][j-1]<<endl;
                cout<<pacific[i][j]<<endl;

                cout<<heights[i-1][j]<<endl;
                cout<<heights[i][j-1]<<endl;
                cout<<heights[i][j]<<endl;



                if((pacific[i-1][j]==1 && heights[i-1][j]<=heights[i][j])  | (pacific[i][j-1]==1 && heights[i][j-1]<=heights[i][j]) )
                {
                    pacific[i][j]=1;
                }
                cout<<i<<j;
            }
        }

            cout<<"done 2";


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
                        sresult.insert(temp);
                    }
                }
            }
        }

            cout<<"done 3";
        for(int i=1;i<nc;i++)
            {
                
                if(pacific[nr-1][i]==1 && atlantic[nr-1][i]==1)
                {
                        vector <int> temp;
                        temp.push_back(nr-1);
                        temp.push_back(i);
                        sresult.insert(temp);

                }
            }
            cout<<"done 4";
        for(int i=1;i<nr;i++)
            {
             
                if(pacific[i][nc-1]==1 && atlantic[i][nc-1]==1)
                {
                        vector <int> temp;
                        temp.push_back(i);
                        temp.push_back(nc-1);
                        
                        sresult.insert(temp);

                }

            }
            cout<<"done 5";
        for( auto x : sresult)
        {
            result.push_back(x);
        }
        return result;
    }
};