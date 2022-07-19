    void Del_X(ListNode &L, int x){
        LNode *p;             //p指向待删除结点
        if(L==NULL) return;   //递归出口
        if(L->val==x){
            p=L;              //删除*L，并让L指向下一结点
            L=L->next;
            free(p);
            Del_X(L,x);
        }
        else{
            Del_X(L->next,x);
        }
    }
//不会断链的。用栈的思想去思考递归过程。这是无返回值的递归过程(void)，在  递 的过程删除结点。
//下面为LeetCode（有返回值的递归过程），是  归 的过程删除结点。
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if (head == nullptr) {
            return head;
        }
        head->next = removeElements(head->next, val);
        return head->val == val ? head->next : head;
    }
};


作者：LeetCode-Solution
链接：https://leetcode.cn/problems/remove-linked-list-elements/solution/yi-chu-lian-biao-yuan-su-by-leetcode-sol-654m/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
