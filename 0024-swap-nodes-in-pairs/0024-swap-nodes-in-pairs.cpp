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
    ListNode* swapPairs(ListNode* head) {

        ListNode dummy(0);
        dummy.next = head;

        ListNode* previous = &dummy;

        while (previous->next != nullptr &&
               previous->next->next != nullptr) {

            // Identify the pair
            ListNode* first = previous->next;
            ListNode* second = first->next;

            // Save the remaining list
            ListNode* nextPair = second->next;

            // Reverse the pair
            second->next = first;

            // Connect first node to remaining list
            first->next = nextPair;

            // Connect previous part to reversed pair
            previous->next = second;

            // Move to the end of processed pair
            previous = first;
        }

        return dummy.next;
    }
};