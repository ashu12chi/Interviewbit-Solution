/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int solve(TreeNode* root)
{
    if(root == NULL)
        return 0;
    int left = solve(root->left);
    int right = solve(root->right);
    if(left == -1 || right == -1)
        return -1;
    if(abs(right-left)>1)
        return -1;
    return 1 + max(left,right);
}
int Solution::isBalanced(TreeNode* A) {
    if(solve(A) == -1)
        return 0;
    return 1;
}
