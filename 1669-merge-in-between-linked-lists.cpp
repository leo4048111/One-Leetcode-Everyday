// https://leetcode.cn/problems/merge-in-between-linked-lists/

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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* head = list1;
        for(int i = 0; i < a - 1; i++)
            head = head->next;

        ListNode* tail = head;

        for(int i = a - 1; i <= b; i++) 
            tail = tail->next;

        head->next = list2;

        while(list2->next != nullptr) list2 = list2->next;

        list2->next = tail;

        return list1;
    }
};