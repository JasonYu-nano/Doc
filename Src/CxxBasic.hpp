#pragma once

namespace Interview
{
    int* GetPtr(int a)
    {
        int* ptr = new int(a);
        return ptr;
    }

    typedef int* (*funcPtr)(int);

    funcPtr p = &GetPtr;
}