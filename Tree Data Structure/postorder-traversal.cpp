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
void postorder1(TreeNode* A)
{
    if(A == NULL)
        return;
    postorder1(A->left);
    postorder1(A->right);
    ans.push_back(A->val);
}
vector<int> Solution::postorderTraversal(TreeNode* A) {
    ans.clear();
    postorder1(A);
    return ans;
}
