/*
**  2. Add Two Numbers
**  You are given two non-empty linked lists representing
**  two non-negative integers. The digits are stored in reverse
**  order and each of their nodes contain a single digit.
**  Add the two numbers and return it as a linked list.
**  You may assume the two numbers do not contain any leading zero,
**  except the number 0 itself.
**
**  Example:
**  Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
**  Output: 7 -> 0 -> 8
**  Explanation: 342 + 465 = 807.
**
**  Definition for singly-linked list.
**  struct ListNode {
**      int val;
**      struct ListNode *next;
**  };
*/

/*
**  First, I add digits from both lists, not forgeting about a carry.
**  Next, I copy the rest of l1/l2 lists in case that one was shorter
**  than another and check if carry still exists. If it does, I create
**  one more node with carry and return the result.
**  O(max(l1, l2)) time, O(max(l1, l2)) space. 
*/

typedef struct ListNode t_node;

t_node *create_new(int val)
{
    t_node *new;
    
    new = (t_node *)calloc(1, sizeof(t_node));
    new->next = NULL;
    new->val = val;
    return (new);
}

t_node *addTwoNumbers(t_node *l1, t_node *l2)
{
    t_node  *new, *prev = NULL;
    t_node  *head = NULL;
    int     carry = 0;
    
    
    while (l1 && l2)
    {
        new = create_new((l1->val + l2->val + carry) % 10);
        carry = (l1->val + l2->val + carry) / 10;
        if (!prev)
            head = new;
        else
            prev->next = new;
        prev = new;
        l1 = l1->next;
        l2 = l2->next;
    }
    while (l1)
    {
        new = create_new((l1->val + carry) % 10);
        carry = (l1->val+ carry) / 10;
        prev->next = new;
        prev = new;
        l1 = l1->next;
    }
    while (l2)
    {
        new = create_new((l2->val + carry) % 10);
        carry = (l2->val + carry) / 10;
        prev->next = new;
        prev = new;
        l2 = l2->next;
    }
    if (carry)
    {
        new = create_new(carry);
        prev->next = new;
    }
    return (head);
}