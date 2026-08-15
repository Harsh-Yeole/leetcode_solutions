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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL)
        return head;
        int n=0;
        ListNode* temp=head;
        while(temp!=NULL){
            n++;
            temp=temp->next;
        }
        k=(k%n);
        if(k==0)
        return head;
        ListNode* prev=NULL;
        ListNode* slow=head;
        ListNode* fast=head;
        int cnt=1;
        while(cnt<k){
            fast=fast->next;
            cnt++;
        }
        while(fast->next!=NULL){
            prev=slow;
            slow=slow->next;
            fast=fast->next;
        }
        prev->next=NULL;
        fast->next=head;
        return slow;
    }
};