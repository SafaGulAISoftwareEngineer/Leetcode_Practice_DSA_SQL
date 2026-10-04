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
    ListNode* reverseKGroup(ListNode* head, int k) {

        ListNode dummy(0);
        dummy.next = head;

        ListNode* previous = &dummy;

        while (true) {

            // Find the kth node
            ListNode* kth = previous;

            for (int i = 0; i < k; i++) {
                kth = kth->next;

                // Fewer than k nodes remain
                if (kth == nullptr) {
                    return dummy.next;
                }
            }

            // Save boundary after this group
            ListNode* groupNext = kth->next;

            // First node of this group
            ListNode* groupStart = previous->next;

            // Reverse exactly this group
            ListNode* prev = groupNext;
            ListNode* current = groupStart;

            while (current != groupNext) {

                ListNode* next = current->next;

                current->next = prev;

                prev = current;
                current = next;
            }

            // Connect previous part to reversed group
            previous->next = prev;

            // Original first node is now the group's tail
            previous = groupStart;
        }
    }
};