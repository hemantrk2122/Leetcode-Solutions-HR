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
    ListNode* partition(ListNode* head, int x) {
        ListNode* small = new ListNode();
        ListNode* high = new ListNode();
        
        ListNode *sh = small, *hh = high;
        
        while(head!=NULL){
            if(head->val<x){
                sh->next = head;
                sh = sh->next;
            }else{
                hh->next = head;
                hh = hh->next;
            }
            head = head->next;
        }
        hh->next = NULL;
        sh->next = high->next;
        
        return small->next;
    }
};