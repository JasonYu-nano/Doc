#pragma once

namespace Interview
{
    void Swap(int& a, int& b)
    {
        int temp = a;
        a = b;
        b = temp;
    }

    int Partition(int data[], int length, int start, int end)
    {
        if (start == end)
            return start;

        int index = (start + end) / 2;
        Swap(data[index], data[end]);

        int bigger = start - 1;
        for (int i = start; i < end; ++i)
        {
            if (data[i] < data[end])
            {
                bigger++;
                if (bigger != i)
                    Swap(data[bigger], data[i]);
            }
        }

        bigger++;
        Swap(data[bigger], data[end]);
        return index;
    }

    void QuickSort(int data[], int length, int start, int end)
    {
        if (data == nullptr || length <= 0)
            return;

        if (start == end)
            return;

        int index = Partition(data, length, start, end);
        if (index > start)
            QuickSort(data, length, start, index - 1);

        if (index < end)
            QuickSort(data, length, index + 1, end);
    }

    int GetRotateAraayMin(int data[], int length)
    {
        if (data == nullptr || length <= 0)
            // throw exception
            return 0;

        int begin = 0;
        int end = length - 1;
        int ret = begin;
        while (data[begin] >= data[end])
        {
            if (end - begin == 1)
                ret = end;

            int mid = (begin + end) / 2;
            if (data[begin] > data[mid])
                end = mid;
            else
                begin = mid;
        }

        return ret;
    }

}