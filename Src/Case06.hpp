#pragma once

namespace Interview
{
    struct BinaryTreeNode
    {
        int value = 0;
        BinaryTreeNode* left = nullptr;
        BinaryTreeNode* right = nullptr;
    };

    BinaryTreeNode* CtorCore(int* preorder, int* inorder, int length)
    {
        if (preorder == nullptr || inorder == nullptr || length <= 0)
            return nullptr;


    };

    BinaryTreeNode* CtorCore(int* startPreorder, int* endPreorder, int* startInorder, int* endInorder)
    {
        int root = *startPreorder;

        BinaryTreeNode* rootNode = new BinaryTreeNode();
        rootNode->value = root;

        if (startPreorder == endPreorder && startInorder == endInorder && *startInorder == *startPreorder)
            return rootNode;

        int* rootInorder = startInorder;

        while (*rootInorder != root && rootInorder < endInorder)
        {
            rootInorder++;
        }

        int leftLength = rootInorder - startInorder;
        int rightLength = endInorder - rootInorder;

        if (leftLength > 0)
            rootNode->left = CtorCore(startPreorder + 1, startPreorder + leftLength, startInorder, rootInorder - 1);
        
        if (rightLength > 0)
            rootNode->right = CtorCore(endPreorder - rightLength, endPreorder, rootInorder + 1, endInorder);

        return rootNode;
    };
}