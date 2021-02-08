#pragma once
#include <stdio.h>
#include <stack>

namespace Interview
{
    struct ListNode
    {
        int value;
        ListNode* next;
    };

    void PrintListReversing(ListNode* head)
    {
        if (head == nullptr)
            return;

        std::stack<int> valueStack;

        ListNode* node = head;
        while (node->next != nullptr)
        {
            valueStack.emplace(node->value);
        }

        while (!valueStack.empty())
        {
            printf("%d\t", valueStack.top());
            valueStack.pop();
        }
    }
}