// https://leetcode.com/problems/decode-ways

class Solution {
public:
    int numDecodings(string s) {
        return decode(s,0,1,s.size())+decode(s,0,2,s.size());
    }

    int decode(string s,int p,int x, int n)
    {
        if(p+x>n)
            return 0;

        string s1=s.substr(p,x);
        cout<<"p: "<<p<<" .x:   "<<x<<"  "<<s1<<endl<<endl;
        if(s[0]!='0' && stoi(s1)>=1 && stoi(s1) <=26)
        {
            cout<<"coming"<<endl;
            if(p+x==n)
            {
                cout<<"undergo  :"<<s1<<endl<<endl;
                return 1;
            }
                
            else
                {
                cout<<"else  :"<<s1<<endl<<endl;
                return decode(s,p+x,1,n) + decode(s,p+x,2,n);

                }
        }
        else 
            return 0;

    }
};