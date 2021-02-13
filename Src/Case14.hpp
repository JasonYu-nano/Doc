#pragma once

namespace Interview
{
    void ReorderOddEven(int* data, unsigned int length)
    {
        if (data == nullptr || length < 2)
        {
            return;
        }

        int* begin = data;
        int* end = data + length - 1;

        while (begin < end)
        {
            while (begin < end && (*begin & 0x1) == 1)
            {
                begin++;
            }

            while (begin < end && (*end & 0x1) == 0)
            {
                end--;
            }

            if (begin < end)
            {
                int temp = *begin;
                *begin = *end;
                *end = temp;
            }
        }
    }
}