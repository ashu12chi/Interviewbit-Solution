/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int count1;
int ans;
void inorder(TreeNode* root,int k)
{
    if(root == NULL)
        return;
    inorder(root->left,k);
    count1++;
    if(count1 == k)
    {
        ans = root->val;
    }
    inorder(root->right,k);
}
int Solution::kthsmallest(TreeNode* A, int B) {
    inorder(A,B);
    count1 = 0;
    return ans;
}
