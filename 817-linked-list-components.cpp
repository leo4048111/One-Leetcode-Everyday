// https://leetcode.cn/problems/linked-list-components/

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
    int numComponents(ListNode* head, vector<int>& nums) {
        int ans = 0;
        bool lastInNums = false;
        bool isNumInNum[99999];
        memset(isNumInNum, 0, sizeof(isNumInNum) * sizeof(bool));
        for(auto& num : nums) isNumInNum[num] = true;
        for(head; head != nullptr; head = head->next)
        {
            int val = head->val;
            if(isNumInNum[val]) {
                if(!lastInNums) ans++;
                lastInNums = true;
            }
            else lastInNums = false;
        }

        return ans;
    }
};