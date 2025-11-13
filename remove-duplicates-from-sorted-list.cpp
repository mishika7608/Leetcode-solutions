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
    ListNode* deleteDuplicates(ListNode* head) {
        struct ListNode *p=head;
        if (head==NULL){
            return head;
        }
        int v=head->val;
        struct ListNode *q=head;
        head=head->next;
        while (head!=NULL)
        {
            if (head->val==v){
                struct ListNode *r=head;
                head=head->next;
                q->next=r->next;
            }
            else{
                v=head->val;
                q=head;
                head=head->next;
            }
        }return p;
    }
};
