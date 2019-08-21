#include<iostream>
#include<vector>
#include"listnode.h"
using namespace std;

class Solution 
{
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) 
    {
        ListNode *head = new ListNode(0);
        ListNode *p = head;
        while (l1 != nullptr && l2 != nullptr) {
            if (l1->val < l2->val) {
                p->next = l1;
                l1 = l1->next;
            } else {
                p->next = l2;
                l2 = l2->next;
            }
            p = p->next;
        }
        p->next = l1 != nullptr ? l1 : l2;
        p = head;
        head = head->next;
        delete p;
        return head;
    }
};


int main() 
{
    ListNode *l1 = buildListNode({1, 2, 4});
    ListNode *l2 = buildListNode({1, 3, 4});
    ListNode *result = Solution().mergeTwoLists(l1, l2);
    cout << result << endl;
    recycle(l1);
    recycle(l2);
    recycle(result);
    return 0;
}