/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
map<int,vector<int>> m;
int val = INT_MIN;
int l;
void help(TreeNode* A,int level,int B)
{
    if(A == NULL)
        return;
    if(A->val == B)
        l = level;
    else
        m[level].push_back(A->val);
    if(A->left && A->right)
    {
        if(A->left->val == B)
            val = A->right->val;
        else if(A->right->val == B)
            val = A->left->val;
    }
    help(A->left,level+1,B);
    help(A->right,level+1,B);
}
vector<int> Solution::solve(TreeNode* A, int B) {
    m.clear();
    val = INT_MIN;
    help(A,0,B);
    if(val == INT_MIN)
        return m[l];
    auto it = m[l].begin();
    while(*it != val)
        it++;
    m[l].erase(it);
    return m[l];
}
