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
    /*ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        struct ListNode *l3=NULL;
        struct ListNode *p=l1;
        struct ListNode *q=l2;
        long long  n1=0;
        long long  n2=0;
        vector<int> num1, num2;
        while (p){
            num1.push_back(p->val);
            p=p->next;
        }
        while (q){
            num2.push_back(q->val);
            q=q->next;
        }
        while (!num1.empty()){
            int v=num1[num1.size()-1];
            num1.pop_back();
            n1=n1*10+v;
        }
        while (!num2.empty()){
            int v=num2[num2.size()-1];
            num2.pop_back();
            n2=n2*10+v;
        }
        n1+=n2;
        if (n1==0){
            struct ListNode *t=new ListNode;
            t->val=0;
            t->next=NULL;
            l3=t;}
        struct ListNode *r=l3;
        while (n1>0){
            int rem=n1%10;
            struct ListNode *t=new ListNode;
            t->val=rem;
            t->next=NULL;
            n1=n1/10;
            if (l3==NULL){
                l3=t;
                r=l3;
            }
            else{
                r->next=t;
                r=t;
            }
        }return l3;
    }*/


    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        struct ListNode *l3=NULL;
        struct ListNode *p=l1;
        struct ListNode *q=l2;
        struct ListNode *r=NULL;
        int c=0;
        while (p && q){
            int v=p->val+q->val+c;
            c=v/10;
            v%=10;
            struct ListNode *t=new ListNode;
            t->val=v;
            t->next=NULL;
            if (l3==NULL){
                l3=t;
                r=l3;
            }
            else{
                r->next=t;
                r=t;
            }
            p=p->next;
            q=q->next;
        }
        while (p){
            int v=p->val+c;
            c=v/10;
            v%=10;
            struct ListNode *t=new ListNode;
            t->val=v;
            t->next=NULL;
                r->next=t;
                r=t;
            p=p->next;
        }
        while (q){
            int v=q->val+c;
            c=v/10;
            v%=10;
            struct ListNode *t=new ListNode;
            t->val=v;
            t->next=NULL;
                r->next=t;
                r=t;
            
            q=q->next;
        }
        if (c){
            struct ListNode *t=new ListNode;
            t->val=c;
            t->next=NULL;
            r->next=t;
            r=t;
        }
        return l3;
    }
};
