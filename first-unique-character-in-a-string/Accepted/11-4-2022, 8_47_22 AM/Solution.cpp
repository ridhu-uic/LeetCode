// https://leetcode.com/problems/first-unique-character-in-a-string

class Solution {
public:
    int firstUniqChar(string s) {
        int a[26]={0};
        int n=s.length();
        for(int i=0;i<s.length();i++)
        {
            a[s[i]-97]++;
        }
        for(int i=0;i<s.length();i++)
        {
            if(a[s[i]-97]==1)
                return i;
        }
        return -1;
    }
};