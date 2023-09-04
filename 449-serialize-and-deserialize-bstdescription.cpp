// https://leetcode.cn/problems/serialize-and-deserialize-bst/description/?envType=daily-question&envId=2023-09-04

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    string serialize(TreeNode* root) {

        string str;
        queue<TreeNode*> q;
        q.push(root);
        while(q.size()){
            auto node = q.front();
            if(node == nullptr){
                str += "null ";
            }else{ 
                str += to_string(node->val);
                str += " ";
                q.push(node->left);
                q.push(node->right);
            }
            q.pop();
        }        
        cout << "str: " << str << endl;
        return str;

    }

    vector<string> convertToString(string data){
        vector<string> vs;
        string str;
        for(int i = 0; i < data.size() ; i++){
            if(data[i] == ' '){
                cout << str << endl;
                vs.push_back(str);
                str = "";
            }else{
                str += data[i];
            }    
        }
        return vs;
    } 
    vector<string> vs;
    TreeNode* deserialize(string data) { // 2 1 # # # 
        

        vs = convertToString(data);
        if(vs.empty() || vs[0] == "null"){
            return nullptr;
        }
        TreeNode *root = new TreeNode(stoi(vs[0]));
        queue<TreeNode*> q;
        q.push(root);
        for(int i = 0; i < vs.size() - 1; ){
            if(vs[++i] != "null"){
                q.front()->left = new TreeNode(stoi(vs[i]));
                q.push(q.front()->left);
            }
            if(vs[++i] != "null"){
                q.front()->right = new TreeNode(stoi(vs[i]));
                q.push(q.front()->right);
            }
            q.pop();
        }
        return root;
    }
};
