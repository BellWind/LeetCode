class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL)
            return NULL;
        return deal(head, head->next);
    }
private:
    ListNode* deal(ListNode* (&fa), ListNode* (&ch)) {
        if(ch == NULL)
            return fa;
        ListNode *son = ch->next;
        if(son == NULL) {
            swap(fa, ch);
            fa->next = ch;
            ch->next = NULL;
            return fa;
        }
        swap(fa, ch);
        fa->next = ch;
        ch->next = deal(son, son->next);
        return fa;
    }
};
