// https://leetcode.com/problems/minimize-xor

class Solution {
public:
    int minimizeXor(int num1, int num2) {
        
        vector <bool> num_v1;
        vector <bool> num_v2;
        int num1_r=num1;
        int count1=0;
        int count2=0;
        while(num1>0)
        {
            num_v1.push_back(num1%2);
            if(num1%2==1)
                count1++;            
            num1=num1/2;
        }
        
        while(num2>0)
        {
            num_v2.push_back(num2%2);
            if(num2%2==1)
                count2++;
            num2=num2/2;
        }
        cout<<"counts"<<count1<<" "<<count2<<"num size"<<num_v1.size()<<"  "<<num_v2.size()<<endl;
        
        if(count1==count2)
            return num1_r;
        
        if(count2>count1)
        {
            for(int i=0;i<num_v1.size();i++)
            {
                if(num_v1[i]==0)
                {
                    num_v1[i]=1;
                    count1++;
                }
                if(count1==count2)
                    break;
            }
            while(count1!=count2)
            {
                num_v1.push_back(1);
                count1++;
            }
        }
        cout<<"num1  :"<<num_v1.size()<<endl;
        int sum=0;
        for(int i=0;i<num_v1.size();i++)
        {
            sum=sum+(num_v1[i]*pow(2,i));
        }
        else
        {
            for(int i=0;i<num_v1.size();i++)
            {
                if(num_v1[i]==1)
                {
                    num_v1[i]=0;
                    count1--;
                }
                if(count1==count2)
                    break;
            }
            /*while(count1!=count2)
            {
                num_v1.push_back(1);
                count1++;
            }*/
        }
        cout<<"num1  :"<<num_v1.size()<<endl;
        int sum=0;
        for(int i=0;i<num_v1.size();i++)
        {
            sum=sum+(num_v1[i]*pow(2,i));
        }
        return sum;
        
    }
};