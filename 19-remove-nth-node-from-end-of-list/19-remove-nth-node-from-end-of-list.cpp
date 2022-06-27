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
        ListNode *curr = new ListNode();
        curr->next = head;
        ListNode* slow = curr;
        ListNode* fast = curr;
        for(int i = 0;i<n;i++)fast = fast->next;
        while(fast->next!=NULL){
            slow = slow->next;
            fast = fast->next;
        }
        slow->next = slow->next->next;
        return curr->next;
    }
};