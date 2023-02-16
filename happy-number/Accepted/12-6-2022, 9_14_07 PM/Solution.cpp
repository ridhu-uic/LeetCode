// https://leetcode.com/problems/happy-number

class Solution {
public:
    bool isHappy(int n) {

        set <int> var;
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
            else if(var.find(sum)!=var.end())
                return false;
            else
                {
                    n=sum;
                    var.insert(sum);
                }
        }
    return false;

    }
};