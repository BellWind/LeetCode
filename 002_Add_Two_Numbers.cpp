class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *ret = findAns(l1, l2, 0);
        if(ret == NULL) return new ListNode(0);
        return ret;
    }
private:
    ListNode* findAns(ListNode* l1, ListNode* l2, int carry) {
        if(l1 != NULL) carry += l1->val;
        if(l2 != NULL) carry += l2->val;
        if(carry == 0 && l1 == NULL && l2 == NULL) return NULL;
        ListNode *cur = new ListNode(carry % 10), *ch1 = NULL, *ch2 = NULL;
        if(l1 != NULL) ch1 = l1->next;
        if(l2 != NULL) ch2 = l2->next;
        cur->next = findAns(ch1, ch2, carry / 10);
        return cur;
    }
};
