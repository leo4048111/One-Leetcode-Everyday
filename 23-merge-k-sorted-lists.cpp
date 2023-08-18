// https://leetcode.cn/problems/merge-k-sorted-lists/description/

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
        vector<int> arr;
        for(auto l : lists) {
            ListNode* node = l;
            while(node) {
                arr.push_back(node->val);
                node = node->next;
            }
        }

        sort(arr.begin(), arr.end());

        ListNode* ans = new ListNode;
        ListNode* cur = ans;
        for(auto& elem : arr) {
            ListNode* node = new ListNode;
            node->val = elem;
            cur->next = node;
            cur = cur->next;
        }

        return ans->next;
    }
};