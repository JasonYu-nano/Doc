#pragma once

namespace Interview
{
    int NumberOf1(int num)
    {
        int ret = 0;
        while (num != 0)
        {
            num = num & (num - 1);
            ret++;
        }
    }

}