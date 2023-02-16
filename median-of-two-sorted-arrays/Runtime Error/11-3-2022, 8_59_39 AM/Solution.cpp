// https://leetcode.com/problems/median-of-two-sorted-arrays

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        double m1;
        int n1=nums1.size();
        double m2;
        int n2=nums2.size();
                    if(n1+n2<=4)
            {
                cout<<"here";
                vector <int> result;
                int i=0;
                int j=0;

                while(i<n1 && j<n2)
                {
                    if(nums1[i]<nums2[j])
                        result.push_back(nums1[i++]);

                    else
                        result.push_back(nums2[j++]);
                }
                while(i<n1)
                    result.push_back(nums1[i++]);

                while(j<n2)
                    result.push_back(nums2[j++]);
                
                int k=n1+n2;
                cout<<endl<<endl;
                for(int i=0;i<n1+n2;i++)
                    cout<<result[i]<<"  ";
                cout<<endl;
                double m;
                if(k%2==0)
                {
                    m=((double)result[k/2]+(double)result[k/2-1])/2;
                    cout<<k<<"  "<<m;
                }
                else
                {
                    m=result[k/2];
                }
                return m;

            }

        if(n1%2==0)
        {
            m1=(double)(nums1[n1/2]+nums1[n1/2-1])/2;
        }
        else
        {
            m1=nums1[n1/2];
        }

        if(n2%2==0)
        {
            m2=(double)(nums2[n2/2]+nums2[n2/2-1])/2;
        }
        else
        {
            m2=nums2[n2/2];
        }
        cout<<m1<<"    "<<m2<<"   "<<(m1==m2)<<endl;


        if(m1==m2)
        {
            cout<<"am I a joke to you?"<<endl;
            return m1;
        }
        else
        {
            cout<<"y me?"<<endl;
            if(m1>m2)
            {
                copy(nums1.begin(),nums1.begin()+n1/2+1,nums1.begin());
                copy(nums2.begin()+n2/2,nums2.end(),nums2.begin());
                return findMedianSortedArrays(nums1,  nums2);
            }
            else
            {
                copy(nums1.begin()+n1/2,nums1.end(),nums1.begin());
                copy(nums2.begin(),nums2.begin()+n2/2+1,nums2.begin());
                return findMedianSortedArrays(nums1,  nums2);
            }
        }
        return (m1+m2)/2;



    }
};