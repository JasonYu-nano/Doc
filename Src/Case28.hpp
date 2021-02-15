#pragma once
#include <stdio.h>

namespace Interview
{
    void Permutation(char* str)
    {
        if (str == nullptr)
            return;

    }

    void Permutation(char* str, char* begin)
    {
        if (*begin == '\0')
            printf("%s\n", str);
        else
        {
            for (char* ch = begin; *ch != '\0'; ch++)
            {
                char temp = *ch;
                *ch = *begin;
                *begin = temp;
                Permutation(str, begin + 1);

                char temp = *ch;
                *ch = *begin;
                *begin = temp;
            }
        }
    }
}