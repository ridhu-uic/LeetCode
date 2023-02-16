// https://leetcode.com/problems/can-place-flowers

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int count=0;
        int size=flowerbed.size();
        
        //if no new plants has to be planted, then there is no need to check;
        if(n==0)
            return true;

        //if size of the flowerbed is 1, then it is plantable if it is not already planted
        //else no
        if(size==1)
        {
            if(flowerbed[0]==1)
                return false;
            else
                return true;
        }
        /*for all other cases the for loop is run and algorithm is checked.
        if checks if the adjacent plots are planted, if adjacents plots are 
        not planted it adds the value of counter.

        later it checks the value of counter.if counter has reached n,
        then    return true.
        */
        for(int i=0;i<size;i++)
        {
            if(flowerbed[i]==1)
                continue;
            if(i==0)
            {
                if(flowerbed[i+1]==0)
                {
                    count=count+1;
                    flowerbed[i]=1;
                }
            }
            else if(i<size-1)
            {
                if(flowerbed[i-1]==0 && flowerbed[i+1]==0)
                {
                    count=count+1;
                    flowerbed[i]=1;
                }
            }
            else
            {
                if(flowerbed[i-1]==0)
                {
                    count=count+1;
                    flowerbed[i]=1;
                }
            }

            if(count==n)
                return true;
        }

        return false;
    }
};