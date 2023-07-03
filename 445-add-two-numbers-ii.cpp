// https://leetcode.cn/problems/add-two-numbers-ii/

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
    ListNode* reverse(ListNode* l)
    {
        ListNode* last = nullptr;
        while(l != nullptr)
        {
            auto x = l->next;
            l->next = last;
            last = l;
            l = x;
        }

        return last;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1 = reverse(l1);
        l2 = reverse(l2);
        ListNode* cur = nullptr;
        int delta = 0;
        while(l1 != nullptr && l2 != nullptr)
        {
            int foo = (l1->val + l2->val + delta);
            int val = foo % 10;
            delta = foo / 10;
            auto x = new ListNode(val, cur);
            cur = x;
            l1 = l1->next;
            l2 = l2->next;
        }

        auto node = l1;
        if(node == nullptr) node = l2;
        
        while(node != nullptr) {
            int foo = (node->val + delta);
            int val = foo % 10;
            delta = foo / 10;
            auto x = new ListNode(val, cur);
            cur = x;
            node = node->next;
        }

        if(delta) 
            cur = new ListNode(delta, cur);

        return cur;
    }
};