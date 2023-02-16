// https://leetcode.com/problems/happy-number

class Solution {
public:
    bool isHappy(int n) {

        int org=n;
        while(1)
        {
            int x=0;      
            int sum=0;
            while(n!=0)
            {
                x=n%10;
                sum=sum+x*x;
                n=n/10;
            }
            cout<<sum<<endl;
            if(sum==1)
                return true;
            else if(sum==org)
                return false;
            else
                n=sum;
        }
    return false;

    }
};