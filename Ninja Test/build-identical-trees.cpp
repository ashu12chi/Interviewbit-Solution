/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int Solution::cntMatrix(TreeNode* A, TreeNode* B) {
    if(A == NULL && B == NULL)
        return 0;
    if(B == NULL)
        return 1 + cntMatrix(A->left,B) + cntMatrix(A->right,B);
    if(A == NULL)
        return 1 + cntMatrix(A,B->left) + cntMatrix(A,B->right);    
}
