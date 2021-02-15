#pragma once

namespace Interview
{
    struct ComplexListNode
    {
        int value;
        ComplexListNode* next;
        ComplexListNode* sibling;
    };

    void CopyComplexListNode(ComplexListNode* head)
    {
        CloneNode(head);
        ConnextSiblingNodes(head);
        ReconnectNode(head);
    }

    void CloneNode(ComplexListNode* head)
    {
        ComplexListNode* rawNode = head;
        while (rawNode != nullptr)
        {
            ComplexListNode* cloneNode = new ComplexListNode();
            cloneNode->value = rawNode->value;
            cloneNode->next = rawNode->next;
            cloneNode->sibling = nullptr;
            rawNode->next = cloneNode;
            rawNode = cloneNode->next;
        }
    }

    void ConnextSiblingNodes(ComplexListNode* head)
    {
        ComplexListNode* node = head;
        while (node != nullptr)
        {
            ComplexListNode* cloneNode = node->next;
            if (node->sibling != nullptr)
                cloneNode->sibling = node->sibling->next;

            node = cloneNode->next;
        }
    }

    ComplexListNode* ReconnectNode(ComplexListNode* head)
    {
        ComplexListNode* node = head;
        ComplexListNode* cloneNode = node->next;
        ComplexListNode* cloneHead = node->next;

        while (node != nullptr)
        {
            node->next = cloneNode->next;
            node = cloneNode->next;

            if (node != nullptr)
            {
                cloneNode->next = node->next;
                cloneNode = node->next;
            }
        }

        return cloneHead;
    }
}