#pragma once

namespace Interview
{
    void ReplaceBlank(char str[], int length)
    {
        if (str == nullptr || length <= 0)
            return;

        int blankCount = 0;
        char word = str[0];

        for (int i = 0; i < length - 1; ++i)
        {
            if (str[i] == ' ')
                blankCount++;
        }

        if (blankCount > 0)
        {
            int newLength = length + 2 * blankCount;
            char* newStr = new char[newLength];
            int index = newLength;

            for (int i = length - 1; i >= 0; --i)
            {
                if (str[i] != ' ')
                    newStr[index--] = str[i];
                else
                {
                    newStr[index--] = '0';
                    newStr[index--] = '2';
                    newStr[index--] = '%';
                }
            }

            str = newStr;
        }
    }
}