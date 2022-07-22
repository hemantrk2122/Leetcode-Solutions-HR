/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode partition(ListNode head, int x) {
        ListNode small = new ListNode(0);
        ListNode high = new ListNode(0);
        
        ListNode sh = small, hh = high;
        
        while(head!=null){
            if(head.val<x){
                sh.next = head;
                sh = sh.next;
            }else{
                hh.next = head;
                hh = hh.next;
            }
            head = head.next;
        }
        hh.next = null;
        sh.next = high.next;
        return small.next;
    }
}