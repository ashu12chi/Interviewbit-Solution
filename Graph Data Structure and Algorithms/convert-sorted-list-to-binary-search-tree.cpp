
TreeNode* solve(ListNode* left,ListNode* right)
{
    if(left == right)
        return NULL;
    if(left->next == right)
        return new TreeNode(left->val);
    ListNode* slow = left;
    ListNode* fast = left->next;
    while(fast!=right && fast->next!=right )
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    TreeNode* root = new TreeNode(slow->val);
    root->left = solve(left,slow);
    root->right = solve(slow->next,right);
    return root;
}
TreeNode* Solution::sortedListToBST(ListNode* A) {
    if(A == NULL)
        return NULL;
    return solve(A,NULL);
}
