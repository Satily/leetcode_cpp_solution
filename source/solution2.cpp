#include<iostream>
#include"listnode.h"
using namespace std;

class Solution 
{
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        ListNode *head = new ListNode(0);
        ListNode *p = head;
        int c = 0;
        while (l1 != nullptr || l2 != nullptr) 
        {
            if (l1 != nullptr)
            {
                c += l1->val;
                l1 = l1->next;
            }
            if (l2 != nullptr)
            {
                c += l2->val;
                l2 = l2->next;
            }
            p->next = new ListNode(c % 10);            
            c /= 10;
            p = p->next;
        }
        if (c != 0) 
        {
            p->next = new ListNode(c);
        }
        p = head;
        head = head->next;
        delete p;
        return head;
    }
};

int main() 
{
    ListNode *l1 = buildListNode({2, 4, 3});
    ListNode *l2 = buildListNode({5, 6, 7});
    ListNode *result = Solution().addTwoNumbers(l1, l2);
    cout << result << endl;
    recycle(l1);
    recycle(l2);
    recycle(result);
    return 0;
}