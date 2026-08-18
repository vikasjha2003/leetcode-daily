class Solution {
public:
    int solve(TreeNode* root, int &res) {
        if(!root) return 0;
        if(!root->left && !root->right) {
            res++;
            return root->val;
        }

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