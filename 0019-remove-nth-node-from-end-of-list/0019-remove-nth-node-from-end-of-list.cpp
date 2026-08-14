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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int cnt=1;
        ListNode* fast=head;
        ListNode* slow=head;
        ListNode* dummy=new ListNode(-1);
        dummy->next=head;
        while(cnt<n && fast!=NULL){
            fast=fast->next;
            cnt++;
        }
        ListNode* prev=dummy;
        while(fast->next!=NULL){
            prev=slow;
            slow=slow->next;
            fast=fast->next;
        }
        prev->next=slow->next;
        return dummy->next;
    }
};