/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<vector<int>> ans;
vector<int> temp;
void solve(TreeNode* A,int B)
{
    if(A == NULL)
        return;
    if(A->left == NULL && A->right == NULL)
    {
        if(A->val == B)
        {
            temp.push_back(B);
            ans.push_back(temp);
            temp.pop_back();
        }
        return;
    }
    temp.push_back(A->val);
    solve(A->left,B-A->val);
    solve(A->right,B-A->val);
    temp.pop_back();
}
vector<vector<int> > Solution::pathSum(TreeNode* A, int B) {
    ans.clear();
    temp.clear();
    solve(A,B);
    return ans;
}
