// Name: Xinrui Yi
// Link: https://leetcode.com/problems/insertion-sort-list/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode *insertionSortList(struct ListNode *head)
{
    struct ListNode dummyHead;
    dummyHead.next = NULL;
    struct ListNode *cur = head;

    while (cur != NULL)
    {
        struct ListNode *prev = &dummyHead;
        while (prev->next != NULL && prev->next->val <= cur->val)
        {
            prev = prev->next;
        }
        struct ListNode *temp = cur->next;
        cur->next = prev->next;
        prev->next = cur;
        cur = temp;
    }
    return dummyHead.next;
}