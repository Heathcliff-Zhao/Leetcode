#include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode* next;
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* pre = NULL;
        ListNode* cur = head;
        ListNode* temp;
        while (cur != NULL) {
            temp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = temp;
        }
        return pre;
    }
};