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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* Head = new ListNode;
        ListNode* curr = Head;
        int carry = 0;
        while(l1 != NULL or l2 != NULL or carry != 0) {
            int x = 0, y = 0;
            if(l1 != NULL) x = l1->val;
            if(l2 != NULL) y = l2->val;
            int sum = carry + x + y;
            carry = sum / 10;
            ListNode* nxt = new ListNode(sum % 10);
            curr->next = nxt;
            curr = curr->next;
            if(l1 != NULL) l1 = l1->next;
            if(l2 != NULL) l2 = l2->next;
        }
        return Head->next;
    }
};
