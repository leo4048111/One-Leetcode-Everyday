// https://leetcode.cn/problems/partition-list/description/

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
    ListNode* partition(ListNode* head, int x) {
        ListNode* listLt = new ListNode();
        ListNode* listGeq = new ListNode();
        ListNode* listLtCur = listLt;
        ListNode* listGeqCur = listGeq;

        while(head) {
            auto tmp = head->next;

            if(head->val >= x) {
                listGeqCur->next = head;
                listGeqCur = head;
                listGeqCur->next = nullptr;
            }
            else {
                listLtCur->next = head;
                listLtCur = head;
                listLtCur->next = nullptr;
            }

            head = tmp;
        }

        listLtCur->next = listGeq->next;

        return listLt->next;
    }
};