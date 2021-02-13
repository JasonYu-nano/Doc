#pragma once

namespace Interview
{
    struct BinaryTreeNode
    {
        int value;
        BinaryTreeNode* left;
        BinaryTreeNode* right;
    };

    void PrintMatrixInCircle(int** data, int col, int row)
    {
        int start = 0;
        while (start <= col / 2 && start <= row / 2)
        {
            int endX = col - start - 1;
            int endY = row - start - 1;

            for (int i = start; i <= endX; ++i)
            {

            }

            for (int i = start + 1; i < endY; ++i)
            {

            }

            for (int i = endX; i >= start; --i)
            {

            }

            for (int i = endY - 1; i > start; --i)
            {

            }
        }
    }
}