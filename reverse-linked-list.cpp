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
        struct ListNode *q=head;
        vector<int> mediate;
        while (head!=0){
            mediate.push_back(head->val);
            head=head->next;
        }
        struct ListNode *p=q;
        while (q!=NULL){
             while (mediate.size()!=0){
                q->val=mediate[mediate.size()-1];
                mediate.pop_back();
                
                q=q->next;
             }

        }
        return p;
    }
};
