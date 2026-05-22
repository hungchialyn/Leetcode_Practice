/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool hasPathSum(struct TreeNode* root, int targetSum) {
    if(root==NULL) return false;

    targetSum = targetSum - root->val;
    if((root->left == NULL) && (root->right == NULL)){
        if(targetSum==0) return true;
    }
    
    return hasPathSum(root->left, targetSum) || hasPathSum(root->right, targetSum);
}