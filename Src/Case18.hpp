#pragma once

namespace Interview
{
    struct BinaryTreeNode
    {
        int value;
        BinaryTreeNode* left;
        BinaryTreeNode* right;
    };

    bool IsTree1HasTree2(BinaryTreeNode* root1, BinaryTreeNode* root2)
    {
        if (root2 == nullptr)
            return true;

        if (root1 == nullptr)
            return false;

        if (root1->value != root2->value)
            return false;

        return IsTree1HasTree2(root1->left, root2->left) && IsTree1HasTree2(root1->right, root2->right);
    }

    bool HasSubTree(BinaryTreeNode* root1, BinaryTreeNode* root2)
    {
        bool result = false;
        if (root1 != nullptr && root2 != nullptr)
        {
            if (root1->value == root2->value)
                result = IsTree1HasTree2(root1, root2);

            if (!result)
                result = HasSubTree(root1->left, root2);

            if (!result)
                result = HasSubTree(root1->right, root2);
        }
        return result;
    }
}