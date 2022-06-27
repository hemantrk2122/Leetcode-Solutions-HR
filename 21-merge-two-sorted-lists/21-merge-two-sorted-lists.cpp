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
        ListNode *a = list1, *b = list2;
        ListNode *d = new ListNode();
        ListNode *c = d;
        while(a!=NULL && b!=NULL){
            if(a->val>b->val){
                c->next = b;
                b=b->next;
            }else{
                c->next = a;
                a=a->next;
            }
            c=c->next;
        }
        while(a!=NULL){
            c->next = a;
            a = a->next;
            c = c->next;
        }
        while(b!=NULL){
            c->next = b;
            b = b->next;
            c = c->next;
        }
        return d->next;
    }
};