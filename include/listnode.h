#include<iostream>
#include<vector>
#include<sstream>

struct ListNode 
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode *buildListNode(const std::vector<int> &data) {
    ListNode *head = new ListNode(0);
    ListNode *p = head;
    for (int datum: data) 
    {
        p->next = new ListNode(datum);
        p = p->next;
    }
    p = head;
    head = head->next;
    delete p;
    return head;
}

void recycle(ListNode *node) {
    ListNode *p;
    while (node != nullptr) 
    {
        p = node;
        node = node->next;
        delete p;
    }
}

std::string flatten(ListNode *node)
{
    std::ostringstream sout;
    sout << "[";
    while (node != nullptr)
    {
        sout << node->val;
        node = node->next;
        if (node != nullptr) {
            sout << ", ";
        }        
    }
    sout << "]";
    return sout.str();
}

std::ostream &operator<<(std::ostream &out, ListNode *node) 
{
    out << flatten(node);
    return out;
}