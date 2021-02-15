#pragma once

namespace Interview
{
    int MoreThanHalfNum(int* number, int length)
    {
        if (number == nullptr || length <= 0)
            return 0;

        int ret = number[0];
        int count = 1;
        for (int i = 1; i < length; ++i)
        {
            if (number[i] != ret)
            {
                count--;
                if (count == 0)
                    ret = number[i];
            }
            else
            {
                count++;
            }
        }

        return ret;
    }
}