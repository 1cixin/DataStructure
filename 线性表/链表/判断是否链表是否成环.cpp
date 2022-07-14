/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head==nullptr)   //这里不能使用(head->==nullptr)，需要考虑没有头结点的情况。
            return false;
        ListNode *f = head;
        ListNode *s = head;
        do{
            if(f->next==nullptr || f->next->next==nullptr)
                return false;
            f = f->next->next;
            s = s->next;
        }while(f!=s);
        return true;
    }
};
