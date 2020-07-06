/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> v;
void inorder(TreeNode* root)
{
    if(root == NULL)
        return;
    inorder(root->left);
    v.push_back(root->val);
    inorder(root->right);
}
int Solution::t2Sum(TreeNode* A, int B) {
    v.clear();
    inorder(A);
    for(int i=0;i<v.size()-1;i++)
    {
        int k = B - v[0];
        if(binary_search(v.begin()+i+1,v.end(),k))
            return 1;
    }
    return 0;
}
