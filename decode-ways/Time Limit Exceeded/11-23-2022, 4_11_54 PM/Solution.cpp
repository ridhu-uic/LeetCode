// https://leetcode.com/problems/decode-ways

class Solution {
    string str;
    int n;
public:
    int numDecodings(string s) {
        str=s;
        n=str.size();
        return decodeS(0,1) + decodeS(0,2);
        
    }

    int decodeS(int p,int x)
    {
        if(p+x>n)
            return 0;

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
                
                return decodeS(p+x,1) + decodeS(p+x,2);
            }
        return 0;
    }
};