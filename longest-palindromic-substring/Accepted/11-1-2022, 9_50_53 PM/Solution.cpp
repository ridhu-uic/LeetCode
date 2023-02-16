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
        int c_i=0;
        for(int i=1;i<2*n+1;i++)
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
                c_i=i;
                maxlength=x-1;
                cout<<c_i<<"   max len"<<maxlength<<endl;
              }

        }
        string s_res="";
        for(int i=c_i-maxlength;i<=c_i+maxlength;i++)
        {
            if(ps[i]!='#')
            s_res=s_res+ps[i];
        }

        return s_res;
        
    }
};