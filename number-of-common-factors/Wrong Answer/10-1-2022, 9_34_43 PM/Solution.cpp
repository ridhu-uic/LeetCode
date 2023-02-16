// https://leetcode.com/problems/number-of-common-factors

class Solution {
public:
    int commonFactors(int a, int b) {
        int n1,n2;
        if(a>b)
        {
            n1=a;
            n2=b;
        }
        else
        {
            n1=b;
            n2=a;
        }
        
        int count =0;
        
        for(int i=1;i<=n1/2;i++)
        {
            if(n1%i==0 && n2%i==0)
                count++;
            
        }
        
        return count;
        
        
    }
};