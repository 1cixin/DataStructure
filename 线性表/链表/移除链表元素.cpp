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
//解法一：迭代。表头和后续元素分别处理，没有解法二好，可以不看。提醒自己记得处理头结点。
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* p = head;
        if(head == nullptr)    return head;
        while(head!=nullptr && head->val==val){
            head = head->next;
        }
        p=head;
        while(p!=nullptr && p->next!=nullptr){
            if(p->next->val == val)
                p->next = p->next->next;
            else
                p = p->next;
        }
        /*或者写成
        while(p && p->next){
            if(p->next->val == val){
                p->next = p->next->next;
                continue;
            }
            p=p->next;
        }
        */
        return head;
    }
};
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
//解法二：迭代。引入哨兵结点充当虚拟表头，比解法一好。
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        struct ListNode* dummyHead = new ListNode(-1,head);
        struct ListNode* temp = dummyHead;
        /*错误构建一：
        ListNode* dummyHead = ListNode(-1,head);
        缺少new, 应该为: = new ListNode(-1,head);
        *错误构建二：
        ListNode dummyHead = ListNode(-1,head);
        ListNode* p = dummyHead.next;
        空指针问题，(temp->next != NULL)会出现空指针问题。
        */
        while(temp->next!=nullptr){
            if(temp->next->val == val){
                temp->next = temp->next->next;
                continue;
            }
            temp = temp->next;
        }
        /*
        不能直接return head;
        head有可能已经改变*/
        return dummyHead->next;
    }
};
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
 //解法三：递归 性能比上面差，但是简洁。简单题可以尝试这么写，复杂题没必要浪费时间。
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if(!head) return head;
        head->next = removeElements(head->next,val);
        //return head->val == val ? head->next : head
        if(head->val == val)
            head = head->next;
        return head;
    }
};
