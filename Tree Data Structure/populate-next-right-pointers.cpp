/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
void Solution::connect(TreeLinkNode* A) {
    queue<pair<TreeLinkNode*,int>> q;
    if(A == NULL)
        return;
    q.push({A,0});
    while(!q.empty())
    {
        TreeLinkNode* temp = q.front().first;
        int level = q.front().second;
        q.pop();
        if(q.empty() || q.front().second != level)
            temp->next = NULL;
        else
            temp->next = q.front().first;
        if(temp->left)
            q.push({temp->left,level+1});
        if(temp->right)
            q.push({temp->right,level+1});
    }
}
