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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector <int> listValue;
        for(int i = 0; i < lists.size(); i++) {
            ListNode* head = lists[i];
            while(head != NULL) {
                listValue.push_back(head->val);
                head = head->next;
            }
        }
        sort(listValue.begin(), listValue.end());
        
        ListNode* Head = new ListNode(0);
        ListNode* cur = Head;
        for(int i = 0; i < listValue.size(); i++) {
            cur->next = new ListNode(listValue[i]);
            cur = cur->next;
        }
        
        return Head->next;
    }
};
