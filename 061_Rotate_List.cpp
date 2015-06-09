class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head->next == NULL || k == 0)
            return head;
        ans = NULL;
        ListNode* tmp = head;
        int tot = 2;
        while(true) {
            if((tmp->next)->next == NULL) {
                int cnt = 0;
                (tmp->next)->next = head;
                k = k % tot;
                if(k == 0)
                    k = tot;
                dfs(head, tmp->next, head, k, cnt);
                break;
            }
            tmp = tmp->next;
            tot++;
        }
        return ans;
    }
private:
    ListNode* ans;
    void dfs(ListNode* head, ListNode* (&fa), ListNode* (&cur), int k, int &cnt) {
        if(cur->next != head)
            dfs(head, cur, cur->next, k, cnt);
        cnt++;
        if(cnt == k)
            ans = cur, fa->next = NULL;
    }
};
