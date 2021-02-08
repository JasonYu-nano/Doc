#pragma once
#include <stack>

namespace Interview
{
    template<typename T>
    class CQueue
    {
    public:
        void Push(const T& value)
        {
            m_Stack1.push(value);
        }

        T Pop()
        {
            if (m_Stack2.size() <= 0)
            {
                while (m_Stack1.size() > 0)
                {
                    m_Stack2.push(m_Stack1.top());
                    m_Stack1.pop();
                }
            }

            if (m_Stack2.size() <= 0)
                throw std::exception("queue is empty");

            T ret = m_Stack2.top();
            m_Stack2.pop();
            return ret;
        }
    private:
        std::stack<T> m_Stack1;
        std::stack<T> m_Stack2;
    };
}