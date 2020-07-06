/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void diagonal(TreeNode* A,int d,map<int,vector<int>>& m)
{
    if(A == NULL)
        return;
    if(A->val!=INT_MIN)
        m[d].push_back(A->val);
    A->val = INT_MIN;
    diagonal(A->left,d+1,m);
    diagonal(A->right,d,m);
}
vector<int> Solution::solve(TreeNode* A) {
    map<int,vector<int>> m;
    diagonal(A,1,m);
    vector<int> ans;
    for(auto it=m.begin();it!=m.end();it++)
    {
        for(int x : it->second)
            ans.push_back(x);
    }
    return ans;
}
