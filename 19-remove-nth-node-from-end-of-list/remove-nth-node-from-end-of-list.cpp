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
    int lenCalc(ListNode* head){
        int cnt=0;
        struct ListNode* p=head;
        while (p!=0){cnt++;p=p->next;}
        return cnt;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int k=lenCalc(head);
        // if (n==1 && k==1){return NULL;delete head;}
        struct ListNode* p=head;
        if (n==k){
            head=head->next;
            delete p;
            return head;
        }
        // struct ListNode* p=head;
        struct ListNode* q=NULL;
        for (int i=0;i<k-n && p!=NULL;i++){
            q=p;
            p=p->next;
        }
        q->next=p->next;
        delete p;
        return head;
    }
};