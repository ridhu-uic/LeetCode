// https://leetcode.com/problems/single-number

class Solution {
public:
    int singleNumber(vector<int>& nums) {
     set <int> dupes;
     set <int> single;
     int i=0;
     while(i<nums.size())
    {
        if(dupes.find(nums[i])==dupes.end() && single.find(nums[i])==single.end())
            {
                single.insert(nums[i]);
            }
        else
        {
            dupes.insert(nums[i]);
            single.erase(nums[i]);
        }
        i++;
     }
    return *single.cbegin();
    }
};