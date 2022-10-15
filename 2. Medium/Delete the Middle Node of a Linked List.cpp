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
    ListNode* deleteMiddle(ListNode* head) {
        if(head == NULL) return head;
        ListNode* cur = head;
        int ct = 1;
        while(cur->next != NULL) {
            ++ct;
            cur = cur->next;
        }
        if(ct == 1) return head->next;
        
        int middle = (ct + 2) / 2, cnt = 1;
        ListNode* ans = head;
        while(head->next != NULL) {
            ++cnt;
            if(cnt == middle) {
                ListNode* temp = head->next;
                head->next = temp->next;
                head = head->next;
                if(head == NULL) break;
            }
            else head = head->next;
        }
        return ans;
    }
};
