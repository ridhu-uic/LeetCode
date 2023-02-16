// https://leetcode.com/problems/can-place-flowers

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int count=0;
        int size=flowerbed.size();
        if(n==0)
            return true;

        if(size==1)
        {
            if(flowerbed[0]==1)
                return false;
            else
                return true;
        }

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