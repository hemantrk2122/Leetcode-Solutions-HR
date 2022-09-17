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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1==NULL)return list2;
        if(list2==NULL)return list1;
        if(list1 == NULL && list2 == NULL)return NULL;
        ListNode *head1 = list1, *head2 = list2;
        ListNode *curr = new ListNode();
        ListNode *dummy = curr;
        while(head1!=NULL and head2!=NULL){
            if(head1->val>head2->val){
                dummy->next = head2;
                head2 = head2->next;
            }
            else{
                dummy->next = head1; 
                head1 = head1->next;
            }
            dummy = dummy->next;
        }
        while(head1!=NULL){
            dummy->next = head1;
            head1 = head1->next;
            dummy = dummy->next;
        }
        while(head2!=NULL){
            dummy->next = head2;
            head2 = head2->next;
            dummy = dummy->next;
        }
        return curr->next;
    }
};