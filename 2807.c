/*
 * Compute the greatest common divisor of two positive integers
 * TODO: USE A MORE EFFICIENT ALGORITHM; THIS IS NAIVE
 */

int gcd(int a, int b) {
    int d = a;
    while (d > 0) {
        if ((a % d == 0) && (b % d == 0)) {
            return d;
        }
        d--;
    }
    return d;
} /* gcd(int, int) */



/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode *insertGreatestCommonDivisors(struct ListNode *head) {
    struct ListNode *a = head;
    struct ListNode *b = head->next;
    while (b != NULL) {
        struct ListNode *new = malloc(sizeof(struct ListNode));
        new->val = gcd(a->val, b->val);
        a->next = new;
        new->next = b;
        a = b;
        b = b->next;
    }
    return head;
}
