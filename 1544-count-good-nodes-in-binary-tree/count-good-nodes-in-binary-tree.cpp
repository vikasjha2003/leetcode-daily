class Solution {
public:
    int countnode (TreeNode* root , int maxi) {
        if(!root) return 0;

        if(maxi <= root -> val) {
            maxi = root -> val;
            return countnode(root->left,maxi) + countnode(root->right,maxi) + 1;
        }

        return countnode(root->left,maxi) + countnode(root->right,maxi);
    }
    int goodNodes(TreeNode* root) {
        return countnode(root,root->val);
    }
};