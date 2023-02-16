// https://leetcode.com/problems/pacific-atlantic-water-flow

class Solution {
public:
    
    int explore_dualPath(vector<vector<int>> heights,vector<vector<int>> &result,vector<vector<int>> &state, int r,int c)
    {
        if(state[r][c]!=-1) 
            return state[r][c];
        state[r][c]=0;
         int dr[4]={1,-1,0,0};
         int dc[4]={0,0,1,-1};
         int state_node=-1;
         int rr,cc;
        cout<<"r    :"<<r<<",c    :"<<c<<endl;
        int m=heights.size();
        int n=heights[0].size();
        
         bool AtlanticFlag=false;
         bool PacificFlag=false;
         bool resultFlag=false;
        
         for(int i=0;i<4;i++)
         {
             rr=r+dr[i];
             cc=c+dc[i];

             if(rr<0)
             {
                 if(rr==-1)
                    PacificFlag=true;
                 continue;
             }
               
             if(cc<0)
             {
                 if(cc==-1)
                    PacificFlag=true;
                 continue;                 
             }

             if(rr>=m)
             {
                 if(rr==m)
                    AtlanticFlag=true;
                 continue;
             }
            if(cc>=n)
            {
                if(cc==n)
                    AtlanticFlag=true;
                continue;
            }
             
             if(heights[rr][cc]<=heights[r][c])
             {
                 if(state[rr][cc]==-1)
                 {
                     state_node=explore_dualPath(heights,result,state,rr,cc);
                     if(heights[rr][cc]<=heights[r][c])
                     {
                         if(state_node==1)
                             PacificFlag=true;
                         if(state_node==2)
                             AtlanticFlag=true;
                            if(state_node==3)
                            {
                                state[r][c]=3;
                                result.push_back(vector<int>{r,c});
                                return state[r][c];
                            }
                     }
                 }
                 else if(state[rr][cc]==0)
                     continue;
                else if(state[rr][cc]==3)
                {
                    PacificFlag=true;
                    AtlanticFlag=true;
                }
                else if(state[rr][cc]==2)
                {
                    AtlanticFlag=true;
                }
                 else if(state[rr][cc]==1)
                 {
                     PacificFlag=true;
                 }
             }
            if(PacificFlag && AtlanticFlag)
            {
                    state[r][c]=3;
                    result.push_back(vector<int>{r,c});
                    return state[r][c];
                
            }
         }
            if(PacificFlag && AtlanticFlag)
            {
                    state[r][c]=3;
                    result.push_back(vector<int>{r,c});
                    return state[r][c];
                
            }
            if(PacificFlag && !AtlanticFlag)
            {
                    state[r][c]=1;
                    return state[r][c];
                
            }
        
            if(!PacificFlag && AtlanticFlag)
            {
                    state[r][c]=2;
                    return state[r][c];
                
            }

        
        return state[r][c];
        
    }
    
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> result;
        result.resize(0);
        
        int m=heights.size();
        int n=heights[0].size();
        vector<vector<int>> state;
        state.resize(m,vector <int> (n));
        bool isPossibleAtRC;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                state[i][j]=-1;
            }
        }
         for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                explore_dualPath(heights,result,state,i,j);
            }
        }
        
        
       return result; 
    }
};