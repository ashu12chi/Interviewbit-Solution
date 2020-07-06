/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> ans;
void preorder1(TreeNode* A)
{
    if(A == NULL)
        return;
    ans.push_back(A->val);
    preorder1(A->left);
    preorder1(A->right);
}
vector<int> Solution::preorderTraversal(TreeNode* A) {
    ans.clear();
    preorder1(A);
    return ans;
}
