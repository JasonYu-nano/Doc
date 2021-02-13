#pragma once

namespace Interview
{
    struct BinaryTreeNode
    {
        int value;
        BinaryTreeNode* left;
        BinaryTreeNode* right;
    };

    void MirrorRecursively(BinaryTreeNode* root)
    {
        if (root == nullptr)
            return;

        if (root->left != nullptr && root->right != nullptr)
        {
            BinaryTreeNode* temp = root->left;
            root->left = root->right;
            root->right = temp;
        }

        MirrorRecursively(root->left);
        MirrorRecursively(root->right);
    }
}