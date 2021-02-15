#pragma once

namespace Interview
{
    int FindGreatestSumOfSubArray(int* data, int length)
    {
        int greatesSum = 0x80000000;
        int sum = 0;

        for (int index = 0; index < length; ++index)
        {
            if (sum <= 0)
            {
                sum = data[index];
            }
            else
            {
                sum += data[index];
            }

            if (greatesSum < sum)
            {
                greatesSum = sum;
            }
        }

        return greatesSum;
    }
}