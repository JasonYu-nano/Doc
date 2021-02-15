#pragma once

namespace Interview
{
    struct BinaryTreeNode
    {
        int value;
        BinaryTreeNode* left;
        BinaryTreeNode* right;
    };

    BinaryTreeNode* Convert(BinaryTreeNode* root)
    {
        if (root == nullptr)
            return root;

        BinaryTreeNode* copiedRoot = root;
        BinaryTreeNode* last = ConvertNode(copiedRoot);
        while (last != nullptr && last->left != nullptr)
        {
            last = last->left;
        }

        return last;
    }

    BinaryTreeNode* ConvertNode(BinaryTreeNode* root)
    {
        if (root == nullptr)
            return nullptr;

        if (root->left != nullptr)
        {
            BinaryTreeNode* lastListNode = ConvertNode(root->left);
            root->left = lastListNode;
            lastListNode->right = root;
        }

        if (root->right != nullptr)
        {
            return ConvertNode(root->right);
        }
        else
            return root;
    }
}