#include<iostream>
#include<vector>
#include<queue>
#include<functional>
#include"listnode.h"
using namespace std;

class Solution 
{
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) 
    {
        priority_queue<ListNode*, vector<ListNode*>, function<bool(ListNode*, ListNode*)>> queue([](ListNode *n1, ListNode *n2){return n1->val > n2->val;});
        for (ListNode *node: lists) {
            if (node != nullptr) {
                queue.push(node);
            }
        }
        ListNode *head = new ListNode(0);
        ListNode *p = head;
        while (!queue.empty()) 
        {
            ListNode *top = queue.top();
            queue.pop();
            p->next = top;
            p = p->next;
            if (top->next != nullptr) {
                queue.push(top->next);
            }            
        }
        p = head;
        head = head->next;
        delete p;
        return head;
    }
};

int main() 
{
    vector<ListNode*> lists = {
        buildListNode({1, 4, 5}),
        buildListNode({1, 3, 4}),
        buildListNode({2, 6})
    };
    cout << Solution().mergeKLists(lists) << endl;
    for (ListNode *node: lists) {
        recycle(node);
    }
    return 0;
}