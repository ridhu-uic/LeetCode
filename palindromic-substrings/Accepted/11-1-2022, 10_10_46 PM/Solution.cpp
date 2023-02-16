// https://leetcode.com/problems/palindromic-substrings

class Solution {
public:
    int countSubstrings(string s) {
                int n=s.size();
        char ps[2*n+1];
        int total=0;
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
            int x=1;
            while(i-x>=0 && i+x<2*n+1)
            {
                if(ps[i-x]==ps[i+x])
                    {
                        x++;
                    }
                else
                    break;
            }
            cout<<x<<"  ";
            total=total+(x)/2;
          


        }

        return total;
        
    }
};