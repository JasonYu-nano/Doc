#pragma once
#include <stack>
#include <cassert>

namespace Interview
{
    class StackWithMin
    {
    private:
        std::stack<int> m_Data;
        std::stack<int> m_Min;

    public:
        void Push(int value)
        {
            m_Data.push(value);

            if (m_Min.size() == 0 || value < m_Min.top())
                m_Min.push(value);
            else
                m_Min.push(m_Min.top());
        }

        void Pop()
        {
            assert(m_Data.size() > 0);
            m_Data.pop();
            m_Min.pop();
        }

        int Min()
        {
            assert(m_Min.size() > 0);
            m_Min.top();
        }
    };
}