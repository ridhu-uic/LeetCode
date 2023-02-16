// https://leetcode.com/problems/longest-substring-without-repeating-characters

class Solution {
public:
    bool areDistinct(string str, int i, int j)
{
 
    // Note : Default values in visited are false
    vector<bool> visited(256);
 
    for (int k = i; k <= j; k++) {
        if (visited[str[k]] == true)
            return false;
        visited[str[k] ] = true;
    }
    return true;
}
    int lengthOfLongestSubstring(string str) {
            int n = str.size();
    int res = 0; // result
    for (int i = 0; i < n; i++)
        for (int j = i; j < n; j++)
            if (areDistinct(str, i, j))
                res = max(res, j - i + 1);
    return res;
   
    }
};