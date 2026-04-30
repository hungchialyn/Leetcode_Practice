/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    if(root->val == p->val){
        return p;
    }
    if(root->val == q->val){
        return q;
    }
    int small = p->val > q->val ? q->val : p->val;
    int large = p->val > q->val ? p->val : q->val;
    if((small < root->val) && (root->val < large)){
        return root;
    }
    if(root->val < small){
        return lowestCommonAncestor(root->right, p, q);
    }
    if(large < root->val){
        return lowestCommonAncestor(root->left, p, q);
    }
    return NULL;
}