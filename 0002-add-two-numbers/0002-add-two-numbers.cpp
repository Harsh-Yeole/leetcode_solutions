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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy=new ListNode(-1);
        ListNode* temp=dummy;
        int sum=0,carry=0;
        while(l1!=NULL && l2!=NULL){
            int v1=l1->val;
            int v2=l2->val;
            sum=v1+v2+carry;
            carry=(sum)/10;
            sum=(sum%10);
            ListNode* node=new ListNode(sum);
            temp->next=node;
            temp=temp->next;
            l1=l1->next;
            l2=l2->next;
        }
        while(l1!=NULL){
            int v1=l1->val;
            int v2=0;
            sum=v1+v2+carry;
            carry=(sum)/10;
            sum=(sum%10);
            ListNode* node=new ListNode(sum);
            temp->next=node;
            temp=temp->next;
            l1=l1->next;
        }
        while(l2!=NULL){
            int v1=0;
            int v2=l2->val;
            sum=v1+v2+carry;
            carry=(sum)/10;
            sum=(sum%10);
            ListNode* node=new ListNode(sum);
            temp->next=node;
            temp=temp->next;
            l2=l2->next;
        }
        if(carry>0){
            ListNode* node=new ListNode(carry);
            temp->next=node;
            temp=temp->next;
        }
        temp=dummy->next;
        return temp;
    }
};