// https://leetcode.com/problems/longest-palindromic-substring

class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();
        int max1=0;
        string s1;
        string s2;
        for(int i=0;i<n;i++)
        {
            int x=1;
            while(i-x>=0 && i+x<n)
            {
                if(s[i-x]==s[i+x])
                    x++;
                else
                    break;
            }
            int length_now1=1+2*(x-1);
            if(length_now1>max1)
            {
            s1=s.substr(i-(x-1),1+2*(x-1));
            cout<<"string 1 of :"<<i;
            cout<<s1<<endl;
            max1=length_now1;
            }
            x=i;
            int y=i+1;
            while(x>=0 && y<n)
            {
                if(s[x]==s[y])
                    {
                        x--;
                        y++;
                    }
                else{
                    break;
                }
            }
            int length_now2=(y-x)-1;
            if(length_now2>max1)
            {
            s1=s.substr(x+1,y-1);
            cout<<"string 2 of :"<<i;
            cout<<s1<<endl;
            max1=length_now2;
            }                

        }

        return s1;
    }
};