// https://leetcode.com/problems/longest-substring-without-repeating-characters

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
    int count=0;
    int maxcount=0;
    string current_string;
    current_string.push_back(s[0]);
    for(int i=0;i<s.size();i++)
    {
        if(current_string.find(s[i])==current_string.npos)
        {
            current_string.push_back(s[i]);
            count++;
            if(count>maxcount)
                maxcount=count;
        }
        else
        {
            int pos=current_string.find(s[i]);
            current_string=current_string.substr(pos+1,current_string.npos);
            count=current_string.size();


        }
    }

    return maxcount;
    }
};