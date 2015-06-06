class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* &head, int n) {
        ListNode* fa = new ListNode(0);
        fa->next = head;
        deleteNthFromEnd(head, fa, n);
        return fa->next;
    }
private:
    int deleteNthFromEnd(ListNode* &head, ListNode* &fa, int n) {
        if(head == NULL)
            return 0;
        int k = deleteNthFromEnd(head->next, head, n) + 1;
        if(k == n)
            fa->next = head->next;
        return k;
    }
};
