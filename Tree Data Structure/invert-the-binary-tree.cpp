/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
TreeNode* Solution::invertTree(TreeNode* A) {
    if(A == NULL)
        return A;
    TreeNode* temp = A->left;
    TreeNode* temp2 = A->right;
    A->left = invertTree(temp2);
    A->right = invertTree(temp);
    return A;
}
