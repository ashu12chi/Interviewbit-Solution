/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
TreeNode* build(vector<int> &inorder, vector<int> &postorder,int low,int high,int& postIndex)
{
    if(low > high)
        return NULL;
    TreeNode* temp = new TreeNode(postorder[postIndex]);
    postIndex--;
    if(low == high)
        return temp;
    int inIndex;
    for(int i=low;i<=high;i++)
    {
        if(inorder[i] == temp->val)
        {
            inIndex = i;
            break;
        }
    }
    temp->left = build(inorder,postorder,low,inIndex-1,postIndex);
    temp->right = build(inorder,postorder,inIndex+1,high,postIndex);
    return temp;
}
TreeNode* Solution::buildTree(vector<int> &inorder, vector<int> &postorder) {
    int postIndex = inorder.size()-1;
    return build(inorder,postorder,0,inorder.size()-1,postIndex);
}
