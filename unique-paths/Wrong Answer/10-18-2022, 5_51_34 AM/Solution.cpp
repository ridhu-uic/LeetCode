// https://leetcode.com/problems/unique-paths

class Solution {

public:
    
    int no_of_path(int r,int c,vector <vector<int>> &paths)    
    {
        int m=paths.size();
        int n=paths[0].size();
        if(r>=m || c>=n)
            return 0;
        if(paths[r][c]!=0)
            return paths[r][c];
        return paths[r][c]=no_of_path(r+1,c,paths)+no_of_path(r,c+1,paths);
    }
    
    
    int uniquePaths(int m, int n) {
        vector <vector<int>> paths;
        paths.resize(m,vector<int>(n));       
        paths[m-1][n-1]=1;
        paths[0][0]=no_of_path(1,0,paths)+no_of_path(0,1,paths);
        return paths[0][0];
    }
};