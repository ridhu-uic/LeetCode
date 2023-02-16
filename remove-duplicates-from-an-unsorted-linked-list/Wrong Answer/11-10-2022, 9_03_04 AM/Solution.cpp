// https://leetcode.com/problems/remove-duplicates-from-an-unsorted-linked-list

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicatesUnsorted(ListNode* head) {
        int flag=0;
        ListNode* i=head;
        ListNode* prev=nullptr;
        ListNode* result=nullptr;
        ListNode* result_head=nullptr;
        ListNode* end=nullptr;
        /*
        while(head!=nullptr)
        {
            cout<<head->val;
            head=head->next;
        }
        */
        while(head!=nullptr)
        {

            flag=0;
            i=head->next;
            prev=head;
            while(i!=nullptr)
            {

                if(i->val == head->val)
                {
                    cout<<"Batista";
                    ListNode* temp = i->next;
                    if(!temp)
                    {
                        prev->next=nullptr;
                        flag=1;
                        i=nullptr;
                        continue;
                    }
                    prev->next=i->next;
                    i=temp;
                    flag=1;

                }
                prev=i;
                i=i->next;
            }
            cout<<"End while"<<endl;
            if(!flag)
            {
                cout<<head->val;
                if(!result_head)
                {
                    ListNode* temp = new ListNode(head->val);
                    result_head=temp;
                    end=result_head;
                }
                else
                {
                    ListNode* temp = new ListNode(head->val);
                    end->next=temp;
                    end=temp;
                }
            }
            
            head=head->next;

      }
      return result_head;
    }
};