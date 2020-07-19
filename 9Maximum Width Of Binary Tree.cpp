/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
    Node* flatten_rec(Node* head){
        Node* curr=head;
        Node* tail=head;
            
            while(curr){
                Node *next=curr->next;
                Node *child=curr->child;
                if(child){
                    Node* new_tail=flatten_rec(child);
                    new_tail->next=next;
                    if(next)next->prev=new_tail;
                    curr->next=child;
                    curr->child=nullptr;
                    child->prev=curr;
                    curr=new_tail;
                    
                }
                else
                    curr=next;
                if(curr)tail=curr;
            }
        return tail;
    }
public:
    Node* flatten(Node* head) {
       if(head)flatten_rec(head);
        return head;
    }
};