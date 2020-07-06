/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int Solution::isSymmetric(TreeNode* A) {
    if(A == NULL)
        return 1;
    if(A->left == NULL && A->right == NULL)
        return 1;
    if(A->left == NULL || A->right == NULL)
        return 0;
    
}
