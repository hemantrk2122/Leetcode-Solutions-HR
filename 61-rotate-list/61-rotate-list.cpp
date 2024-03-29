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
        if(head == NULL)return head;
        int size = 1;
        ListNode *curr = head;
        while(curr->next!=NULL){
            size++;
            curr = curr->next;
            
        }
        k%=(size);
        cout<<size<<endl;
        curr->next = head;
        curr = head;
        for(int i = 0;i<size-k-1;i++){
            curr = curr->next;
        }
        head = curr->next;
        curr->next = NULL;
        return head;
    }
};