// https://leetcode.cn/problems/fu-za-lian-biao-de-fu-zhi-lcof/submissions/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    unordered_map<Node*, int> _m;
    int findNodePos(Node* head, Node* node)
    {
        if(_m.find(node) != _m.end()) return _m[node];
        int pos = 0;
        for(; head != nullptr; head = head->next)
        {
            if(head == node) { 
                _m[node] = pos;
                return pos;
            }

            pos++;
        }

        return -1;
    }

    Node* copyRandomList(Node* head) {
        Node* ansHead = new Node(INT_MIN);
        Node* cur = nullptr;
        Node* pre = ansHead;
        for(Node* tmp = head; tmp != nullptr; tmp = tmp->next)
        {
            cur = new Node(tmp->val);
            pre->next = cur;
            pre = cur;
        }

        Node* tmp2 = head;

        for(Node* tmp = ansHead->next; tmp != nullptr; tmp = tmp->next, tmp2 = tmp2->next)
        {
            if(tmp2->random != nullptr)
            {
                int pos = findNodePos(head, tmp2->random);
                Node* tmp3 = ansHead->next;
                while(pos) {
                    tmp3 = tmp3->next;
                    pos--;
                }

                tmp->random = tmp3;
            }
        }

        return ansHead->next;
    }
};