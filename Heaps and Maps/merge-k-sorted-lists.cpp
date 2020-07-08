ListNode* Solution::mergeKLists(vector<ListNode*> &A) 
{
    int n=A.size();
    ListNode *head=new ListNode(0);
    map<int,int> hash;
    for(int i=0;i<n;i++)
    {
        while(A[i]!=NULL)
        {
            hash[A[i]->val]++;
            A[i]=A[i]->next;
        }
    }
    ListNode *head1=head;
    for(auto i:hash)
    {   
        while(hash[i.first]!=0)
        {
            ListNode *temp=new ListNode(i.first);
            head1->next=temp;
            head1=head1->next;
            hash[i.first]--;
        }
    }
    return head->next;
}
