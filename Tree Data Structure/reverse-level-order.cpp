/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> Solution::solve(TreeNode* A) {
    vector<int> ans;
    queue<TreeNode*> q;
    if(A == NULL)
        return ans;
    q.push(A);
    while(!q.empty())
    {
        auto p = q.front();
        q.pop();
        ans.push_back(p->val);
        if(p->right)
            q.push(p->right);
        if(p->left)
            q.push(p->left);
    }
    reverse(ans.begin(),ans.end());
    return ans;
}
