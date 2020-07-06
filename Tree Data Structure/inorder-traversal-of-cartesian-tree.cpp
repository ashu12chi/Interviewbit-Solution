/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
TreeNode* build(vector<int>& A,int l,int r)
{
    if(l>r)
        return NULL;
    int maxe = 0;
    int maxi = -1;
    for(int i=l;i<=r;i++)
    {
        if(A[i] > maxe)
        {
            maxe = A[i];
            maxi = i;
        }
    }
    TreeNode* root = new TreeNode(A[maxi]);
    root->left = build(A,l,maxi-1);
    root->right = build(A,maxi+1,r);
    return root;
}
TreeNode* Solution::buildTree(vector<int> &A) {
    return build(A,0,A.size()-1);
}
