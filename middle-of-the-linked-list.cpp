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
    ListNode* middleNode(ListNode* head) {
        struct ListNode *p=head;
        int c=0;
        while (p){
            c++;
            p=p->next;
        }
        c=c/2+1;
        p=head;
        while (c>1){
            p=p->next;
            c--;
        }
        return p;
    }
};
