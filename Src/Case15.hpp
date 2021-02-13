#pragma once

namespace Interview
{
    struct ListNode
    {
        int value;
        ListNode* next;
    };

    ListNode* FindKthToTail(ListNode* head, unsigned int k)
    {
        if (head == nullptr || k == 0)
            return nullptr;

        ListNode* kNode = head;
        ListNode* indexNode = head;
        int diff = 0;

        while (indexNode != nullptr)
        {
            if (diff >= k - 1)
                kNode = kNode->next;
            else
                diff++;
            indexNode = indexNode->next;
        }

        if (diff == k - 1)
            return kNode;
        else
            return nullptr;
    }
}