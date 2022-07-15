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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int count = 0;  //换轨次数
        if(headA==nullptr || headB==nullptr)
            return nullptr;
        ListNode *a = headA;
        ListNode *b = headB;
        while(a!=b){
            if(a->next == nullptr){
                a = headB;
                count++;
            }else{
                a = a->next;
            }
            if(b->next == nullptr){
                b = headA;
                count++;
            }else{
                b = b->next;
            }
            if(count>2) return nullptr;
        }
        return a;
    }
};
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *a = headA, *b = headB;
        while(a!=nullptr || b!=nullptr){
            if(a==b) return a;
            a = a==nullptr?headB:a->next;
            b = b==nullptr?headA:b->next;
        }
        return nullptr;
    }
};
