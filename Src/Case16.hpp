#pragma once

namespace Interview
{
    struct ListNode
    {
        int value;
        ListNode* next;
    };

    ListNode* ReverseList(ListNode* head)
    {
        if (head == nullptr)
            return head;

        ListNode* front = nullptr;
        ListNode* current = head;
        ListNode* back = head->next;

        while (back != nullptr)
        {
            current->next = front;
            front = current;
            current = back;
            back = current->next;
        }
        current->next = front;

        return current;
    }
}