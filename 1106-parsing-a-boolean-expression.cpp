// https://leetcode.cn/problems/parsing-a-boolean-expression/

class Solution {
public:
    bool parseBoolExpr(string expression) {
        stack<char> s_op;
        stack<bool> s_operand;

        for(auto& c : expression)
        {
            switch(c)
            {
                case 't': 
                s_operand.push(true);
                break;
                case 'f':
                s_operand.push(false);
                break;
                case '(':
                case '|':
                case '&':
                case '!':
                case ',':
                s_op.push(c);
                break;
                case ')':
                {
                    std::vector<bool> tmp;
                    tmp.push_back(s_operand.top()); s_operand.pop();
                    while(s_op.top() != '(')
                    {
                        s_op.pop();
                        tmp.push_back(s_operand.top()); s_operand.pop();
                    }
                    s_op.pop(); // eat '(';
                    char op = s_op.top(); s_op.pop();
                    bool result;
                    if(op == '!') result = !tmp[0];
                    else if(op == '&') {
                        result = true;
                        for(auto e : tmp) result &= e;
                    }
                    else {
                        result = false;
                        for(auto e : tmp) result |= e;
                    }
                    s_operand.push(result);
                }
                break;
            }            
        }

        return s_operand.top();
    }
};