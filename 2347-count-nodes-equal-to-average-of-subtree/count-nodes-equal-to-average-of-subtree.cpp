class Solution {
public:
    pair<int,int> DFS(TreeNode* root, int &count) {
        if(!root) return {0,0};

        auto it = DFS(root->left,count);
        auto iz = DFS(root->right,count);

        int sum = root->val;
        int cnt = 1;
        sum += it.first + iz.first;
        cnt += it.second + iz.second;

        if(sum / cnt == root->val) count++;

        return {sum,cnt};
    }

    int averageOfSubtree(TreeNode* root) {
        int res = 0;
        DFS(root,res);

        return res;
    }
};