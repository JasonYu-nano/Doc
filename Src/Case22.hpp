#pragma once
#include <stack>

namespace Interview
{
    bool IsPopOrder(int* push, int* pop, int length)
    {
        if (push == nullptr || pop == nullptr || length <= 0)
            return false;

        std::stack<int> stack;
        int pushIndex = 0;
        for (int index = 0; index < length; ++index)
        {
            int popValue = pop[index];

            while (pushIndex < length)
            {
                if (stack.size() == 0 || stack.top() != popValue)
                {
                    stack.push(push[pushIndex]);
                    pushIndex++;
                }
            }

            if (stack.top() != popValue)
                return false;
            else
                stack.pop();
        }

        return true;
    }
}