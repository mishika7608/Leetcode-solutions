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
    struct ListNode *root=NULL;

    ListNode* split(ListNode* head, int size){
        while (--size && head) head = head->next;
        if (!head) return NULL;
        ListNode* sec=head->next;
        head->next = NULL;
        return sec;
    }

    ListNode* merge(ListNode* l1, ListNode* l2){
        ListNode dummy(0);
        ListNode *tail = &dummy;

        while (l1 && l2){
            if (l1->val < l2->val){
                tail->next = l1;
                l1=l1->next;
            }else{
                tail->next = l2;
                l2=l2->next;
            }
            tail=tail->next;
        }tail->next = l1?l1:l2;
        return dummy.next;
    }




    ListNode* sortList(ListNode* head) { 
        if (head==NULL || head->next==NULL){return head;}
        int len=0;

        for (ListNode *p=head;p;p=p->next){len++;}
        ListNode dummy(0);
        dummy.next=head;

        for (int size=1;size<len;size<<=1){
            ListNode* curr = dummy.next;
            ListNode *tail = &dummy;

            while (curr){
                ListNode* left = curr;
                ListNode* right = split(left,size);
                curr = split(right, size);

                tail->next = merge(left, right);
                while (tail->next) tail=tail->next;
            }
        }return dummy.next;

    }

};


// class Solution {
// public:
// // fee in s do sorted insert
//     struct ListNode* head2=NULL;
//     set<ListNode*> s;
//     void sortedInsert(set<ListNode*> ele){
//         ListNode *p= NULL;
//         for (auto l : s ){
//             if (head2==NULL || l->val<head2->val){
//                 l->next=head2;
//                 head2=l;
//             }
//             else{
//                 struct ListNode* p= head2;
//                 while (p->val<l->val && p->next->val<l->val || p->next!=NULL){p=p->next;}
//                 if (p->next==NULL){p->next=l;l->next=NULL;}
//                 else{
//                     l->next=p->next;
//                     p->next=l;
//                 }
//             }
//         }
        
//     }
//     ListNode* sortList(ListNode* head) {
//         if (head==NULL || head->next==NULL){return head;}
//         while (head){
//             s.insert(head);
//             head=head->next;
//         }
//         sortedInsert(s);
//         return head2;
//     }
// };