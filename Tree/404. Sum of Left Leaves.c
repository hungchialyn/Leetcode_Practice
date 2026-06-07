/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
void add(struct TreeNode* root, int *sum){
    if(root == NULL){
        return;
    }
    add(root->right, sum);
    add(root->left, sum);
    if(root->left&&root->left->left == NULL&&root->left->right==NULL){
        *sum = *sum + root->left->val;
    }
}
int sumOfLeftLeaves(struct TreeNode* root) {
    int sum = 0;
    add(root, &sum);
    return sum;
}