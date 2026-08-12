class FindElements {
public:
    unordered_set<int> st;
    void buildTree(TreeNode* root) {
        if(root-> val == -1) {
            root->val = 0;
            st.insert(0);
        }
        if(root->left) {
            root->left->val = root->val * 2 + 1;
            st.insert(root->left->val);
            buildTree(root->left);
        }
        if(root->right) {
            root->right->val = root->val * 2 + 2;
            st.insert(root->right->val);
            buildTree(root->right);
        }
    }
    FindElements(TreeNode* root) {
        buildTree(root);
    }
    
    bool find(int target) {
        return st.find(target) != st.end();
    }
};