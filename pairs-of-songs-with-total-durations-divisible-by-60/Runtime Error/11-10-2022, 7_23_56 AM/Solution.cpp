// https://leetcode.com/problems/pairs-of-songs-with-total-durations-divisible-by-60

class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {

        long count=0;
        map <int, int> songs;
        for(int i=0;i<60;i++)
        {
            songs[i]=0;
        }
        for(int i=0;i<time.size();i++)
        {
            songs[time[i]%60]++;
        }

        count=songs[0]*(songs[0]-1)/2;
        int i=1;
        int j=59;
        while(i<j)
        {
            count=count+songs[i++]*songs[j--];
        }
        count=count+songs[30]*(songs[30]-1)/2;
        return count;
        
    }
};