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
    ListNode* reverseBetween(ListNode* head, int left, int right) {

        // 1. Create an extra node before head
        ListNode dummy(0);

        // 2. Connect dummy to the original list
        dummy.next = head;

        // 3. Pointer to the node before left
        ListNode* before = &dummy;

        // 4. Move before to position left - 1
        for (int i = 1; i < left; i++) {
            before = before->next;
        }

        // 5. First node of the section
        ListNode* current = before->next;

        // 6. Reverse the section
        for (int i = 0; i < right - left; i++) {

            // Node that we want to move to the front
            ListNode* next = current->next;

            // Remove next from its current position
            current->next = next->next;

            // Put next before current
            next->next = before->next;

            // Connect before to next
            before->next = next;
        }

        // 7. Return the actual head
        return dummy.next;
    }
};