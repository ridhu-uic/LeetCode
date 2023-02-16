// https://leetcode.com/problems/fair-candy-swap

class Solution {
public:
    vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {
        int na = aliceSizes.size();
        int nb = bobSizes.size();
        int suma=0;
        int sumb=0;
        for (int i=0;i<na;i++)
            suma=suma+aliceSizes[i];
        for (int i=0;i<nb;i++)
            sumb=sumb+bobSizes[i];
        vector <int> result;
        int mid = (suma+sumb)/2;
        int diff=abs(suma-sumb)/2;
        if(suma>sumb)
        {
            for(int i = 0;i<na;i++)
            {
                for(int j=0;j<nb;j++)
                {
                    if(aliceSizes[i]-bobSizes[j]==diff)
                        {
                            result.push_back(aliceSizes[i]);
                            result.push_back(bobSizes[j]);
                            return result;
                        }
                }
            }
        }
        else{
            for(int i = 0;i<na;i++)
            {
                for(int j=0;j<nb;j++)
                {
                    if(bobSizes[j]-aliceSizes[i]==diff)
                        {
                            result.push_back(aliceSizes[i]);
                            result.push_back(bobSizes[j]);
                            return result;
                        }
                }
            }
        }
        return result;

    }
};
