/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
stack<TreeNode*> s;
BSTIterator::BSTIterator(TreeNode *root) {
    while(root!=NULL)
    {
        s.push(root);
        root = root->left;
    }
}

/** @return whether we have a next smallest number */
bool BSTIterator::hasNext() {
    if(!s.empty())
        return true;
    return false;
}

/** @return the next smallest number */
int BSTIterator::next() {
    TreeNode* temp = s.top();
    s.pop();
    BSTIterator(temp->right);
    return temp->val;
}

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
