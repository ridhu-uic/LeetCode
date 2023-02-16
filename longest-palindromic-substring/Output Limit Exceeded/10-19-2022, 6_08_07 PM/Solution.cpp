// https://leetcode.com/problems/longest-palindromic-substring

class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();
        string maxS="";
        string tempS;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i+j>=n)
                    continue;

                tempS=s.substr(i, j+1);
                //tempS.compare(const _Tp &__svt)
                cout<<tempS<<endl;
                string k=tempS;
                reverse(tempS.begin(),tempS.end());
                if(!tempS.compare(k))
                {
                    cout<<"    "<<tempS<<"   "<<k<<endl;
                    if(maxS.size()<j+1)
                        maxS=tempS;
                }
                cout<<"maxS     "<<maxS<<endl;
            }

        }
        return maxS;
    }
};