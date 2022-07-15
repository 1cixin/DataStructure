/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *f = head, *s = head;
        for(int i=0;i<n;i++)
            f = f->next;
        while(f!=nullptr && f->next!=nullptr){
            f = f->next;
            s = s->next;
        }
        if(f==nullptr)  return head->next;//当要求删除头结点时，该解法选择跳过头结点，不用做删除头结点的麻烦操作。需要注意的是，该题head->val直接等于第一个val（相当于示例1中head->val==1），并非是无意义。
        else{
            s->next = s->next->next;
            return head;
        }
    }
};



//根据方法一和方法二，如果我们能够得到的是倒数第n个节点的前驱节点而不是倒数第n个节点的话，删除操作会更加方便。因此我们可以考虑在初始时将second指向哑节点，其余的操作步骤不变。
//这样一来，当first遍历到链表的末尾时，second的下一个节点就是我们需要删除的节点。

作者：LeetCode-Solution
链接：https://leetcode.cn/problems/remove-nth-node-from-end-of-list/solution/shan-chu-lian-biao-de-dao-shu-di-nge-jie-dian-b-61/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* first = head;
        ListNode* second = dummy;
        for (int i = 0; i < n; ++i) {
            first = first->next;
        }
        while (first) {
            first = first->next;
            second = second->next;
        }
        second->next = second->next->next;
        ListNode* ans = dummy->next;
        delete dummy;
        return ans;
    }
};
