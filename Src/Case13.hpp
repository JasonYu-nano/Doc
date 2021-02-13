#pragma once

namespace Interview
{
    struct ListNode
    {
        int value;
        ListNode* next;
    };

    void DeleteNode(ListNode* head, ListNode* pendingDelete)
    {
        if (pendingDelete == nullptr || head == nullptr)
            return;

        if (pendingDelete == head)
        {
            head = head->next;
            return;
        }

        if (pendingDelete->next == nullptr)
        {
            delete pendingDelete;
            pendingDelete = nullptr;
            return;
        }

        ListNode* next = pendingDelete->next;
        pendingDelete->value = next->value;
        pendingDelete->next = next->next;
        delete next;
        next = nullptr;
    }
}