// https://leetcode.com/problems/first-unique-character-in-a-string

class Solution {
public:
    int firstUniqChar(string s) {
        vector <int> a(26,0);
        int pos=-1;
        for(int i=s.size()-1;i>=0;i--)
        {
            a[s[i]-'a']++;
            if(a[s[i]-'a']==1)
                pos=i;
            if(pos!=-1 && a[s[pos]-'a']>1)
                pos=-1;
        }
        return pos;
    }
};