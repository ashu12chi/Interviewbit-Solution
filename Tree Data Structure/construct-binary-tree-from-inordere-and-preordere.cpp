/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
TreeNode* build(vector<int> &preorder, vector<int> &inorder,int low,int high,int& preIndex)
{
    if(low > high)
        return NULL;
    TreeNode* temp = new TreeNode(preorder[preIndex]);
    preIndex++;
    if(low == high)
        return temp;
    int inIndex = -1;
    for(int i=low;i<=high;i++)
    {
        if(inorder[i] == temp->val)
        {
            inIndex = i;
            break;
        }
    }
    temp->left = build(preorder,inorder,low,inIndex-1,preIndex);
    temp->right = build(preorder,inorder,inIndex+1,high,preIndex);
    return temp;
}
TreeNode* Solution::buildTree(vector<int> &preorder, vector<int> &inorder) {
    int preIndex = 0;
    return build(preorder,inorder,0,inorder.size()-1,preIndex);
}
