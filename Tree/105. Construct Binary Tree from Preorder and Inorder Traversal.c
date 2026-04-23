/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int findMid(int target, int* inorder, int start, int end){
    for(int i = start; i <= end; i++){
        if(target==inorder[i]){
            return i;
        }
    }
    return -1;
}
struct TreeNode* helper(int* preorder, int* inorder, int inorderStart, int inorderEnd, int* preorderIdx){
    if(inorderStart > inorderEnd) return NULL;

    struct TreeNode* root = malloc(sizeof(struct TreeNode));
    root->val = preorder[(*preorderIdx)++];

    int mid = findMid(root->val, inorder, inorderStart, inorderEnd);
    if(mid<0) return NULL;

    root->left  = helper(preorder, inorder, inorderStart, mid-1, preorderIdx);
    root->right = helper(preorder, inorder, mid+1, inorderEnd, preorderIdx);

    return root;
}
struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize) {
    int preorderIdx = 0;
    int start = 0;
    return helper(preorder, inorder, start, preorderSize-1, &preorderIdx);
}