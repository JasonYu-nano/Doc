#pragma once

namespace Interview
{
    extern bool ExistNumInArray(int* matrix, unsigned int width, unsigned int height, int num)
    {
        if (matrix == nullptr)
            return false;

        int row = 0; // hang
        int column = width - 1; // lie

        while (row < height && column >= 0)
        {
            if (matrix[row * width + column] > num)
            {
                column--;
                continue;
            }

            if (matrix[row * width + column] < num)
            {
                row++;
                continue;
            }

            return true;
        }

        return false;
    }
}