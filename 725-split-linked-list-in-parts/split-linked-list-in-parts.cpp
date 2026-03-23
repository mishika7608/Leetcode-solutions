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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> result(k, NULL);
        // Step 1: Find length
        int n = 0;
        ListNode* temp = head;
        while (temp) {
            n++;
            temp = temp->next;
        }
        // Step 2: Calculate sizes
        int base = n / k;
        int extra = n % k;
        ListNode* curr = head;
        for (int i = 0; i < k; i++) {
            if (!curr) {
                result[i] = NULL;
                continue;
            }
            result[i] = curr;
            int partSize = base + (extra > 0 ? 1 : 0);
            if (extra > 0) extra--;
            for (int j = 1; j < partSize; j++) {
                curr = curr->next;
            }
            ListNode* nextPart = curr->next;
            curr->next = NULL;
            curr = nextPart;
        }
        return result;
    }
};