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
    ListNode* reverse(ListNode* head,int k){
        int cnt=1;
        ListNode* temp=head;
        while(cnt<k && temp!=NULL){
            temp=temp->next;
            cnt++;
        }
        if(temp==NULL)
        return head;
        ListNode* next=temp->next;
        ListNode* prev=NULL;
        ListNode* first=head;
        temp=head;
        cnt=1;
        while(cnt<=k && temp!=NULL){
            ListNode* store=temp->next;
            temp->next=prev;
            prev=temp;
            if(cnt!=k && store!=NULL)
            temp=store;
            else
            break;
            cnt++;
        }
        if(first!=NULL)
        first->next=reverse(next,k);
        return temp;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        return reverse(head,k);
    }
};