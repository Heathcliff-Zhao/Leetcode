#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode, * p = head;
        int sum = 0, pre = 0;
        while (l1 && l2) {
            sum = l1->val + l2->val + pre;
            pre = sum / 10;
            sum = sum % 10;
            p->next = new ListNode;
            p = p->next;
            p->val = sum;
            l1 = l1->next;
            l2 = l2->next;
        }
        ListNode* l;
        if (l1)
            l = l1;
        else
            l = l2;
        while (l) {
            sum = l->val + pre;
            pre = sum / 10;
            sum = sum % 10;
            p->next = new ListNode;
            p = p->next;
            p->val = sum;
            l = l->next;
        }
        if (pre) {
            p->next = new ListNode;
            p = p->next;
            p->val = pre;
        }
        return head->next;
    }
};