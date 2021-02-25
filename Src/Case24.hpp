#pragma once

namespace Interview
{
    int sum(int* array, int count)
    {
        if (array == nullptr || count <= 0)
            return;

        int ret = 0;
        for (int index = 0; index < count; ++index)
        {
            ret += *(array + index);
        }
    }
}