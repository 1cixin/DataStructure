//给你单链表的头节点 head ，请你反转链表，并返回反转后的链表。

//解法一：迭代。按原始顺序迭代结点，并将它们逐个移动到列表的头部。
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
    ListNode* reverseList(ListNode* head) {
        if(head==nullptr || head->next==nullptr)   return head;
        // 构造一个虚假的链表头
        ListNode dummy = ListNode(-1,head);
        ListNode *prev = head;
        ListNode *pCur = head->next;
        do{
            prev->next = pCur->next;
            pCur->next = dummy.next;
            dummy.next = pCur;
            //改变pCur指针
            pCur = prev->next;
        }while(pCur!=nullptr);//画两个循环就基本清晰。比较难理解，多练习记忆。
        return dummy.next;
    }
};


//解法二：递归。大问题分解成相似的子问题，确定返回条件。先递，反转的操作留在归的过程。
 /**
     * 以链表1->2->3->4->5举例
     * @param head
     * @return
     */
    public ListNode* reverseList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            /*
                直到当前节点的下一个节点为空时返回当前节点
                由于5没有下一个节点了，所以此处返回节点5
             */
            return head;
        }
        //递归传入下一个节点，目的是为了到达最后一个节点
        ListNode* newHead = reverseList(head->next);
                /*
            第一轮出栈，head为5，head->next为空，返回5
            第二轮出栈，head为4，head->next为5，执行head->next->next=head也就是5->next=4，
                      把当前节点的子节点的子节点指向当前节点
                      此时链表为1->2->3->4<->5，由于4与5互相指向，所以此处要断开4->next=nullptr
                      此时链表为1->2->3->4<-5
                      返回节点5
            第三轮出栈，head为3，head->next为4，执行head->next->next=head也就是4->next=3，
                      此时链表为1->2->3<->4<-5，由于3与4互相指向，所以此处要断开3->next=nullptr
                      此时链表为1->2->3<-4<-5
                      返回节点5
            第四轮出栈，head为2，head->next为3，执行head->next->next=head也就是3->next=2，
                      此时链表为1->2<->3<-4<-5，由于2与3互相指向，所以此处要断开2->next=nullptr
                      此时链表为1->2<-3<-4<-5
                      返回节点5
            第五轮出栈，head为1，head->next为2，执行head->next->next=head也就是2->next=1，
                      此时链表为1<->2<-3<-4<-5，由于1与2互相指向，所以此处要断开1->next=nullptr
                      此时链表为1<-2<-3<-4<-5
                      返回节点5
            出栈完成，最终头节点5->4->3->2->1
         */
        head->next->next = head;
        head->next = nullptr;
        return newHead;
    }
