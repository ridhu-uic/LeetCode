// https://leetcode.com/problems/longest-substring-without-repeating-characters

class Solution {
public:

    int lengthOfLongestSubstring(string str) {
    int n = str.size();
    int res = 0; // result
 
    for (int i = 0; i < n; i++) {
         
        // Note : Default values in visited are false
        vector<bool> visited(256);  
 
        for (int j = i; j < n; j++) {
 
            // If current character is visited
            // Break the loop
            if (visited[str[j]] == true)
                break;
 
            // Else update the result if
            // this window is larger, and mark
            // current character as visited.
            else {
                res = max(res, j - i + 1);
                visited[str[j]] = true;
            }
        }
 
        // Remove the first character of previous
        // window
        visited[str[i]] = false;
    }
    return res;
    }
};