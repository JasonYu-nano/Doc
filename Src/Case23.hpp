#pragma once
#include <deque>

namespace Interview
{
    struct BinaryTreeNode
    {
        int value;
        BinaryTreeNode* left;
        BinaryTreeNode* right;
    };

    void PrintFromTopToBottom(BinaryTreeNode* root)
    {
        if (root == nullptr)
            return;

        std::deque<BinaryTreeNode*> pendingPrintList;
        pendingPrintList.push_back(root);

        while (pendingPrintList.size() > 0)
        {
            BinaryTreeNode* node = pendingPrintList.front();
            pendingPrintList.pop_front();
            if (node->left)
                pendingPrintList.push_back(node->left);

            if (node->right)
                pendingPrintList.push_back(node->right);

            printf("%d ", node->value);
        }
    }
}