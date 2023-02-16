// https://leetcode.com/problems/longest-substring-without-repeating-characters

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
    int count=0;
    int maxcount=0;
    string current_string;
    for(int i=0;i<s.size();i++)
    {
        if(current_string.find(s[i])==current_string.npos || current_string.empty())
        {
            current_string.push_back(s[i]);
            cout<<"string after added"<<current_string<<"in the"<<i<<"th iteration."<<endl;
            count++;
            if(count>maxcount)
                maxcount=count;
        }
        else
        {
            int pos=current_string.find(s[i]);
            current_string=current_string.substr(pos+1,current_string.npos);
            cout<<"string after added"<<current_string<<endl;
            count=current_string.size();


        }
    }

    return maxcount;
    }
};