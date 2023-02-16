// https://leetcode.com/problems/decode-ways

class Solution {
public:
    int numDecodings(string s) {
        int n=s.size();
        vector <int> dp;
        dp.resize(n+1);
        dp[0]=1;
        int total=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]>='1' && s[i]<='9')
                {
                    dp[i+1]=dp[i];
                    cout<<"hello";
                    if((i-1 >= 0 && (s[i]>='1' && s[i]<='6' ) && (s[i-1]=='1' || s[i-1]=='2')) )
                        {
                            dp[i+1]=dp[i]+1;
                            if(i+1<n && s[i+1]=='0')
                                dp[i+1]--;
                        }
                }
            if(s[i]=='0')
            {
                if(i-1 < 0  || s[i-1]=='0')
                    return 0;
                if(i-1 >= 0 && (s[i-1]>=1 || s[i-1]<=2))
                    dp[i+1]=dp[i];
                
            }


            cout<<dp[i+1]<<endl;

        }
    return dp[n];
    }
};