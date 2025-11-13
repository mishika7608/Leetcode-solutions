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

    int sizelist(ListNode*head){
        int c=0;
        struct ListNode *p=head;
        while (p){c++;p=p->next;}
        return c;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if (head==NULL || head->next==NULL){return head;}
        int n=sizelist(head);
        k%=n;
        while (k--){
            struct ListNode *p=head;
            struct ListNode *q=NULL;
            while (p->next){q=p;p=p->next;}
            q->next=NULL;
            p->next=head;
            head=p;
        }
        return head;
    }
};
