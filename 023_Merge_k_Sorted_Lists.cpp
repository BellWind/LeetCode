class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0)
            return NULL;
        int n = lists.size(), M;
        n <<= 2;
        ListNode *tree[n + 4];
        for(int i = 1; i < n + 4; i++)
            tree[i] = NULL;
        n >>= 2;
        for(M = 1; M <= n + 1; M <<= 1) ;
        for(int i = M + 1; i <= M + n; i++)
            tree[i] = lists[i - M - 1];
        for(int i = M - 1; i; i--) {
            tree[i] = mergeTwoLists(tree[i << 1], tree[i << 1 | 1]);
        }
        return tree[1];
    }
private:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == NULL)
            return l2;
        if(l2 == NULL)
            return l1;
        if(l1->val > l2->val)
            swap(l1, l2);
        l1->next = mergeTwoLists(l1->next, l2);
        return l1;
    }
};
