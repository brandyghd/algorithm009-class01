//21. 合并两个有序链表
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *res = new ListNode(0);
        ListNode *head = res;
        while(l1 != NULL && l2 != NULL)
        {
            if(l1 -> val > l2 -> val)
            {
                res -> next = l2;
                l2 = l2 -> next;
            }
            else
            {
                res -> next = l1;
                l1 = l1 -> next;
            }
            res = res -> next;
        }
        if(l1 != NULL)
        {
            res -> next = l1;
        }
        if(l2 != NULL)
        {
            res -> next = l2;
        }
        res = head;
        head = head -> next;
        delete res;
        return head;
    }
};