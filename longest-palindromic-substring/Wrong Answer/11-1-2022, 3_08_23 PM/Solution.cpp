// https://leetcode.com/problems/longest-palindromic-substring

class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();
        char ps[2*n+1];
        for(int i=0;i<2*n+1;i++)
        {
            if(i%2==0)
                ps[i]='#';
            else
                ps[i]=s[i/2];
            cout<<ps[i];
        }
        cout<<endl;
        int maxlength=0;
        string res;
        for(int i=0;i<2*n+1;i++)
        {
            int x=0;
            while(i-x>=0 && i+x<2*n+1)
            {
                if(ps[i-x]==ps[i+x])
                    x++;
                else
                    break;
            }
            if(x-1>maxlength)
            {
                if(ps[i]=='#')
                {
                    res=s.substr((i-1)/2,x-1);
                }
                else
                {
                    res=s.substr((i-1)/2,x-1);
                }
                cout<<"i ="<<i<<"x-1  ="<<x-1<<endl;
                maxlength=x-1;
                cout<<res<<endl;
            }

        }

        return res;
        
    }
};