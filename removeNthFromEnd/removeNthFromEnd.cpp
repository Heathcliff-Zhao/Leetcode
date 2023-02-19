#include <iostream>
using namespace std;
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

struct ListNode
{
    int val;
    ListNode* next;
    ListNode() :val(0), next(nullptr) {}
    ListNode(int x) :val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) :val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int depth = 0;
        ListNode* p = head;
        while (p->next) {
            p = p->next;
            depth++;
        }
        if (depth + 1 == n) {
            return head->next;
        }
        p = head;
        for (int i = 0; i < depth - n; i++)
            p = p->next;
        p->next = p->next->next;
        return head;
    }
};

