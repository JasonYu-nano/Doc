#pragma once

namespace Interview
{
    struct ListNode
    {
        int value;
        ListNode* next;
    };

    ListNode* MergeList(ListNode* head1, ListNode* head2)
    {
        ListNode* source = nullptr;

        while (head1 != nullptr && head2 != nullptr)
        {
            ListNode* nextNode = head1->value < head2->value ? head1 : head2;
            if (head1->value < head2->value)
            {
                nextNode = head1;
                head1 = nextNode->next;
                nextNode->next = nullptr;
            }
            else
            {
                nextNode = head2;
                head2 = nextNode->next;
                nextNode->next = nullptr;
            }

            if (source == nullptr)
            {
                source = nextNode;
            }
            else
            {
                source->next = nextNode;
            }
        }
        

        if (head1 != nullptr || head2 != nullptr)
        {
            ListNode* nextNode = head1 != nullptr ? head1 : head2;
            if (source == nullptr)
            {
                source = nextNode;
            }
            else
            {
                source->next = nextNode;
            }
        }

        return source;
    }
}