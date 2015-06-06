class Solution {
public:
    ListNode* reverseKGroup(ListNode* (& head), int k) {
        if(head == NULL || k == 1)
            return head;
        ListNode* tail = head;
        int cnt = 0;
        while(tail && cnt < k) {
            tail = tail->next;
            cnt++;
        }
        if(cnt < k)
            return head;
        if(tail)
            tail = reverseKGroup(tail, k);
        return reverseKNodes(head, tail, k, 1);
    }
private:
    ListNode* reverseKNodes(ListNode* (& head), ListNode* fa, int k, int c) {
        if(k == c) {
            head->next = fa;
            return head;
        }
        ListNode* son = head->next;
        head->next = fa;
        return reverseKNodes(son, head, k, c + 1);
    }
};
