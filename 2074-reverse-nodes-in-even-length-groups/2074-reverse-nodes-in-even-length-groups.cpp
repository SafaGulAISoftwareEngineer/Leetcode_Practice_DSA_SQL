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
    ListNode* reverseEvenLengthGroups(ListNode* head) {
        ListNode dummy(0);
        dummy.next = head;

        ListNode* prevGroupTail = &dummy;
        int groupSize = 1;

        while (prevGroupTail->next != nullptr) {
            ListNode* groupStart = prevGroupTail->next;
            ListNode* groupEnd = groupStart;

            // Find the last node actually present in this group.
            int actualLength = 1;

            while (actualLength < groupSize &&
                   groupEnd->next != nullptr) {
                groupEnd = groupEnd->next;
                actualLength++;
            }

            // Save the next group before changing any links.
            ListNode* nextGroup = groupEnd->next;

            if (actualLength % 2 == 0) {
                // Reverse this group.
                ListNode* prev = nextGroup;
                ListNode* current = groupStart;

                while (current != nextGroup) {
                    ListNode* next = current->next;
                    current->next = prev;
                    prev = current;
                    current = next;
                }

                // Connect the previous part to the new group head.
                prevGroupTail->next = prev;

                // Original groupStart is now the group's tail.
                prevGroupTail = groupStart;
            } else {
                // Group stays unchanged.
                prevGroupTail = groupEnd;
            }

            groupSize++;
        }

        return dummy.next;
    }
};