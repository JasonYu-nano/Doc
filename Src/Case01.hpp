#pragma once
#include <memory>

namespace Interview
{
    class CMyString
    {
    public:
        CMyString(char* data = nullptr) : m_Data(data) {}
        CMyString(const CMyString& rhs)
        {
            m_Data = rhs.m_Data;
        }
        ~CMyString()
        {
            delete[] m_Data;
        }

        CMyString& operator=(const CMyString& rhs)
        {
            if (&rhs != this) //!!!!
            {
                CMyString temp(rhs);
                char* tempData = temp.m_Data;
                temp.m_Data = m_Data;
                m_Data = tempData;
            }

            return *this;
        }
    private:
        char* m_Data;
    };
}