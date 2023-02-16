// https://leetcode.com/problems/pairs-of-songs-with-total-durations-divisible-by-60

class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {

        long count=0;
        int songs[60]={0};
        for(int i=0;i<time.size();i++)
        {
            int a=time[i]%60;

            if(a==0)
                count=count+songs[0];
            else
                count=count+songs[60-a];
            songs[a]++; 
        }

        return count;
        
    }
};