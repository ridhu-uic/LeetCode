// https://leetcode.com/problems/decode-ways

class Solution {
    string str;
    int n;
    vector<vector<int>> dp;
public:
    int numDecodings(string s) {
        str=s;
        n=str.size();
        dp.resize(n+1,vector<int>(2,-1));
        dp[0][0]=decodeS(0,1);
        dp[0][1]=decodeS(0,2);

        return dp[0][0]+dp[0][1];
        
    }

    int decodeS(int p,int x)
    {

        if(dp[p][x-1]!=-1)
            return dp[p][x-1];

        cout<<"p    :"<<p<<"x   :"<<x<<endl;
        string s1=str.substr(p,x);
        cout<<"             "<<s1<<endl;
        if(s1[0]=='0')
            return 0;

        if(stoi(s1) >= 1 && stoi(s1) <= 26)
            {
                if(p+x==n)
                    {
                        cout<<"returns 1 p    :"<<p<<"x   :"<<x<<endl;
                        return 1;
                    }
                
                if(p+x<=n)
                {
                dp[p+x][0]=decodeS(p+x,1);
                dp[p+x][1]=decodeS(p+x,2);

                return dp[p+x][0]+dp[p+x][1];
                }
                else
                    return 0;
            }
        return 0;
    }
};