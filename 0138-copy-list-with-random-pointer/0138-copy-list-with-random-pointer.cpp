/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* temp=head;
        while(temp!=NULL){
            Node* node=new Node(temp->val);
            Node* store=temp->next;
            temp->next=node;
            node->next=store;
            temp=store;
        }
        temp=head;
        while(temp!=NULL){
            if(temp->random==NULL){
                temp->next->random=NULL;
            }
            else{
                temp->next->random=temp->random->next;
            }
            temp=temp->next->next;
        }
        Node* dummy=new Node(-1);
        dummy->next=head;
        Node* res=dummy;
        temp=head;
        while(temp!=NULL){
            res->next=temp->next;
            temp->next=temp->next->next;
            res=res->next;
            temp=temp->next;
        }
        return dummy->next;
    }
};