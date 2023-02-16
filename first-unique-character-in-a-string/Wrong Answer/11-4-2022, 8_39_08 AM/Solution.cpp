// https://leetcode.com/problems/first-unique-character-in-a-string

class Solution {
public:
    int firstUniqChar(string s) {
        vector <int> a(26,0);
        int pos=-1;
        for(int i=s.size()-1;i>=0;i--)
        {
            a[s[i]-'a']++;
        }
        for(int i=0;i<26;i++)
        {
            if(a[i]==1  )
            {

                if(pos ==-1)
                    pos=i;
            
                else
                {
                    int fpos=s.find('a'+i);
                    if(fpos<pos)
                        pos=fpos;
                }

            }
        }
        return pos;
    }
};