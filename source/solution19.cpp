#include<iostream>
#include"listnode.h"
using namespace std;

class Solution 
{
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
        ListNode *p = head;
        int length = 0;
        while (p != nullptr) 
        {
            p = p->next;
            length++;
        }
        int target = length - n;
        if (target == 0) {
            head = head->next;
        }
        else 
        {
            p = head;
            for (int i = 0; i < target - 1; i++) {
                p = p->next;
            }
            ListNode *q = p->next;
            p->next = q->next;            
        }
        return head;
    }
};

int main() 
{
    ListNode *head = buildListNode({1, 2, 3, 4, 5});
    ListNode *result = Solution().removeNthFromEnd(head, 5);
    cout << result << endl;
    recycle(head);
    recycle(result);
    return 0;
}