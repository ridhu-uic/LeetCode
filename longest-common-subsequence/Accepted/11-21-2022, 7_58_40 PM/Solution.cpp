// https://leetcode.com/problems/longest-common-subsequence

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
     int n1=text1.size();
     int n2=text2.size();
     vector<vector<int>> lcs;
     lcs.resize(n1+1,vector<int>(n2+1) );
    for(int i=n1-1;i>=0;i--)
    {
        for(int j=n2-1;j>=0;j--)
        {
            if(text1[i]==text2[j])
            {
                lcs[i][j]=1+lcs[i+1][j+1];
            }
            else
            {
                lcs[i][j]=max(lcs[i][j+1],lcs[i+1][j]);
            }
        }
    }
    return lcs[0][0];
    }
};