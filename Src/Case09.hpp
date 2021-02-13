#pragma once

namespace Interview
{
    unsigned long long Fibonacci(unsigned int n)
    {
        if (0 == n)
            return 0;
        else if (1 == n)
            return 1;
        else
        {
            unsigned long long n_2 = 0;
            unsigned long long n_1 = 1;
            for (unsigned int index = 2; index <= n; index++)
            {
                unsigned long long result = n_2 + n_1;
                n_2 = n_1;
                n_1 = result;
            }
            return n_1;
        }
    }

}