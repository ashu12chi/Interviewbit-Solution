/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<vector<int>> Solution::zigzagLevelOrder(TreeNode* A) {
    if(A == NULL)
        return {};
    stack<TreeNode*> q,q2;
    vector<vector<int>> ans;
    q.push(A);
    vector<int> v;
    bool flag = true;
    while(!q.empty())
    {
        TreeNode* p = q.top();
        q.pop();
        v.push_back(p->val);
        if(flag)
        {
            if(p->left)
                q2.push(p->left);
            if(p->right)
                q2.push(p->right);
        }
        else
        {
            if(p->right)
                q2.push(p->right);
            if(p->left)
                q2.push(p->left);
        }
        if(q.empty())
        {
            swap(q,q2);
            ans.push_back(v);
            flag != flag;
            v.clear();
        }
    }
    return ans;
}
