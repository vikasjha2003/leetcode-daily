class FindElements {
public:
    unordered_set<int> st;
    FindElements(TreeNode* root) {
        queue<TreeNode*> q;
        root-> val = 0;
        q.push(root);

        while(!q.empty()) {
            TreeNode* temp = q.front();
            q.pop();
            st.insert(temp->val);
            
            if(temp -> left) {
                temp->left->val = temp->val * 2 + 1;
                q.push(temp->left);
            }
            if(temp -> right) {
                temp->right->val = temp->val * 2 + 2;
                q.push(temp->right);
            }
        }
    }
    
    bool find(int target) {
        return st.find(target) != st.end();
    }
};