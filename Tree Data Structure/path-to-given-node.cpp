/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
bool solve1(TreeNode* A,int b,vector<int>& ans)
{
    if(A == NULL)
        return false;
    if(A->val == b)
        return true;
    if(A->left)
    {
        ans.push_back(A->left->val);
        if(solve1(A->left,b,ans))
            return true;
        ans.pop_back();
    }
    if(A->right)
    {
        ans.push_back(A->right->val);
        if(solve1(A->right,b,ans))
            return true;
        ans.pop_back();
    }
    return false;
}
vector<int> Solution::solve(TreeNode* A, int B) {
    vector<int> ans;
    ans.push_back(A->val);
    solve1(A,B,ans);
    return ans;
}
