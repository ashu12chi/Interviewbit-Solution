/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
TreeNode* build(const vector<int>& A,int l,int r)
{
    if(l>r)
        return NULL;
    if(l == r)
        return (new TreeNode(A[l]));
    int mid = (l+r)/2;
    TreeNode* temp = new TreeNode(A[mid]);
    temp->left = build(A,l,mid-1);
    temp->right = build(A,mid+1,r);
    return temp;
}
TreeNode* Solution::sortedArrayToBST(const vector<int> &A) {
    return build(A,0,A.size()-1);
}
