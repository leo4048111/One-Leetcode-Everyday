// https://leetcode.cn/problems/swap-nodes-in-pairs/

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
    ListNode* swapPairs(ListNode* head) {
        if(!head) return head;

        ListNode* ret = new ListNode();
        ret->next = head;
        ListNode* pprev = ret, *prev = head, *cur = head->next;
        for(;;)
        {
            pprev->next = prev;
            if(prev && !cur) return ret->next;

            prev->next = cur->next;
            cur->next = prev;
            pprev->next = cur;

            if(!prev->next) return ret->next;

            pprev = prev; 
            prev = prev->next;
            cur = prev->next;
        }

        return ret->next;
    }
};