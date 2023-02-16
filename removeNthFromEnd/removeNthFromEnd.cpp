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
        ListNode* p = head;
        while (!isNthFromEnd(p, n + 1)) {
            p = p->next;
        }
        if (!(p->next)) { return nullptr; }
        //if (!(p->next->next)) { return head->next; }
        p->next = p->next->next;
        return head;
    }
private:
    bool isNthFromEnd(ListNode* now, int n) {
        while (--n) {
            if (!(now->next))
                return true;
            now = now->next;
        }
        if (now->next) {
            return false;
        }
        return true;
    }
};

