/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void help(TreeNode* A,int level,map<int,int>& ump)
{
    if(A == NULL)
        return;
    ump[level] = A->val;
    help(A->left,level+1,ump);
    help(A->right,level+1,ump);
}
vector<int> Solution::solve(TreeNode* A) {
    map<int,int> ump;
    help(A,1,ump);
    vector<int> v;
    for(auto it=ump.begin();it!=ump.end();it++)
    {
        v.push_back(it->second);
    }
    return v;
}
