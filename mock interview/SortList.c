// Name: Xinrui Yi
// link: https://leetcode.com/problems/sort-list/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *merge(struct ListNode *l1, struct ListNode *l2)
{
    struct ListNode dummyHead;
    struct ListNode *tail = &dummyHead;
    while (l1 != NULL && l2 != NULL)
    {
        if (l1->val < l2->val)
        {
            tail->next = l1;
            l1 = l1->next;
            tail = tail->next;
        }
        else
        {
            tail->next = l2;
            l2 = l2->next;
            tail = tail->next;
        }
    }
    if (l1 != NULL)
        tail->next = l1;
    if (l2 != NULL)
        tail->next = l2;
    return dummyHead.next;
}

struct ListNode *getMid(struct ListNode *head)
{
    struct ListNode *slow = head;
    struct ListNode *fast = head;
    struct ListNode *prev = NULL;
    while (fast != NULL && fast->next != NULL)
    {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    if (prev != NULL)
    {
        prev->next = NULL;
    }
    return slow;
}

struct ListNode *sortList(struct ListNode *head)
{
    if (head == NULL || head->next == NULL)
        return head;
    struct ListNode *mid = getMid(head);
    struct ListNode *left = sortList(head);
    struct ListNode *right = sortList(mid);
    return merge(left, right);
}