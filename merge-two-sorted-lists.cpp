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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1==NULL && list2==NULL){
            return list1;
        }
        if (!list1) return list2;
        if (!list2) return list1;
        struct ListNode *last=NULL;
        struct ListNode *ans=new ListNode(-1);

        if (list1->val<list2->val){
            ans=list1;
            last=list1;
            list1=list1->next;
            last->next=NULL;
        }
        else{
            ans=list2;
            last=list2;
            list2=list2->next;
            last->next=NULL;
        }
        while (list1!=NULL && list2!=NULL)
        {
            if (list1->val < list2->val){
                last->next=list1;
                last=list1;
                list1=list1->next;
                last->next=NULL;
            }
            else{
                last->next=list2;
                last=list2;
                list2=list2->next;
                last->next=NULL;
            }
        }
        if (list1!=NULL){
            last->next=list1;
        }
        else{
            last->next=list2;
        }
    return ans;
        /*struct ListNode *p=list1;
        struct ListNode *q=list2;
        if ((p->val) <= (q->val)){
            ans=p;
            last=p;
            last->next=NULL;
            p=p->next;
        }
        else{
            ans=q;
            last=q;
            last->next=NULL;
            q=q->next;
        }
        while (p && q){
            if (p->val<=q->val){
                last->next=p;
                last=p;
                p=p->next;
            }
            else{
                last->next=q;
                last=q;
                q=q->next;
            }
        }
        if (p!=0){
            last->next=p;
        }
        else{
            last->next=q;
        }
        return ans;*/
    }
    
};
