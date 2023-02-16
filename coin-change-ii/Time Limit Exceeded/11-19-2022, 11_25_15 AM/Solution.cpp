// https://leetcode.com/problems/coin-change-ii

class Solution {
public:
    int change(int amount, vector<int>& coins) {
            
        set<vector <int >> dp[amount+1];
        vector <int> zero(1,0);
        dp[0].insert(zero);
        for(int i=1;i<=amount;i++)
        {
            for(int j=0;j<coins.size();j++)
            {
                if(i-coins[j]>=0)
                {
                    cout<<"coin and amount matched  "<<i<<"   "<<coins[j]<<endl;
                        set<vector<int >>::iterator itr;
                        
                        for (itr = dp[i-coins[j]].begin(); itr != dp[i-coins[j]].end(); itr++) {
                        vector <int> x(*itr);
                        x.push_back(coins[j]);
                        sort(x.begin(),x.end());
                        dp[i].insert(x);
                        }
                }
            }
        } 


        cout<<endl<<endl;

        for(int i=0;i<=amount;i++)
        {
            cout<<"amount = "<<i<<"    "<<"coins   :";
            set<vector<int >>::iterator itr;
            for (itr = dp[i].begin(); itr != dp[i].end(); itr++) {
                    for(int j=0;j<itr->size();j++)
                    {
                        cout<<*(itr->begin()+j)<<"    ";
                    }
                }
                cout<<endl;
             
        }
        
        return dp[amount].size();
    }
};