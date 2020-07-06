/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void solve(TreeNode* A,TreeNode** first,TreeNode** middle,TreeNode** last,TreeNode** prev)
{
    if(A == NULL)
        return;
    solve(A->left,first,middle,last,prev);
    if(*prev && (*prev)->val > A->val)
    {
        if(*first)
        {
            *last = A;
        }
        {
            *first = *prev;
            *middle = A;
        }
    }
    *prev = A;
    solve(A->right,first,middle,last,prev);
}
vector<int> Solution::recoverTree(TreeNode* A) {
    TreeNode* first = NULL;
    TreeNode* middle = NULL;
    TreeNode* last = NULL;
    TreeNode* prev = NULL;
    solve(A,&first,&middle,&last,&prev);
    vector<int> ans;
    if(last)
    {
        ans.push_back(first->val);
        ans.push_back(last->val);
        sort(ans.begin(),ans.end());
        return ans;
    }
    ans.push_back(first->val);
    ans.push_back(middle->val);
    sort(ans.begin(),ans.end());
    return ans;
}
