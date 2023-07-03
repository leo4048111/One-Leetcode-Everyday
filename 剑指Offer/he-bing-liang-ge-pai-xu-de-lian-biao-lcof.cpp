// https://leetcode.cn/problems/he-bing-liang-ge-pai-xu-de-lian-biao-lcof/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* cur = new ListNode(INT_MIN);
        ListNode* head = cur;
        while(l1 != nullptr && l2 != nullptr)
        {
            ListNode* node = nullptr;
            if(l1->val > l2->val) {
                node = l2;
                l2 = l2->next;
            } else {
                node = l1;
                l1 = l1->next;
            }

            auto x = new ListNode(node->val);
            if(cur != nullptr) cur->next = x;
            cur = x;            
        }

        auto node = l1;
        if(node == nullptr) node = l2;

        while(node != nullptr)
        {
            auto x = new ListNode(node->val);
            if(cur != nullptr) cur->next = x;
            cur = x;
            node = node->next;
        }

        return head->next;
    }
};