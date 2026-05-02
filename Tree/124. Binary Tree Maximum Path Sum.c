/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int max(int a, int b){
    return a > b ? a : b;
}
int dfs(struct TreeNode* root, int *maxsum){
    if(root == NULL) return 0;

    int left = max(0, dfs(root->left, maxsum));
    int right = max(0, dfs(root->right, maxsum));

    *maxsum = max(*maxsum, left + right + root->val);

    return root->val + max(left, right); // 回傳單邊最大路徑
}
int maxPathSum(struct TreeNode* root) {
    int maxsum = INT_MIN;

    dfs(root, &maxsum);

    return maxsum;
}