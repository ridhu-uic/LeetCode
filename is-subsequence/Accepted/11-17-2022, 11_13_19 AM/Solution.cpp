// https://leetcode.com/problems/is-subsequence

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int tsize=t.size();
        int k=0;
        for(int i=0;i<tsize;i++)
        {
            if(s[k]==t[i])
            {
                k++;
            }
        }
        if (k==s.size())
            return true;

        return false;
    }
};