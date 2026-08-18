class Solution {
public:
    int solve(TreeNode* root, int &res) {
        if(!root) return 0;

        int lowerMax = max(solve(root->left,res),solve(root->right,res));
        if(root->val >= lowerMax) res++;

        return max(root->val,lowerMax);
    }
    int countDominantNodes(TreeNode* root) {
        int res = 0;
        solve(root,res);
        return res;
    }
};