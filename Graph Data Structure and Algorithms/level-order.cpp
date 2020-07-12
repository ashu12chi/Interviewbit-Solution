/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<vector<int> > Solution::levelOrder(TreeNode* A) {
    if(A == NULL)
        return {};
    queue<pair<TreeNode*,int>> q;
    q.push({A,0});
    vector<vector<int>> v;
    map<int,vector<int>> m;
    while(!q.empty())
    {
        auto p = q.front();
        m[p.second].push_back(p.first->val);
        q.pop();
        if(p.first->left)
            q.push({p.first->left,p.second+1});
        if(p.first->right)
            q.push({p.first->right,p.second+1});
    }
    for(auto it=m.begin();it!=m.end();it++)
    {
        v.push_back(it->second);
    }
    return v;
}
