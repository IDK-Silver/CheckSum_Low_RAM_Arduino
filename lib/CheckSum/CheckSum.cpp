#include "CheckSum.h"

int getSplitSumNum(BoolArray *need_check, const int k, int start, int end)
{
    int Sum = 0;
    for (int index = start; index < end; index++)
    {
        int power = 1;
        for (int split_index = index * k; split_index < (index + 1) * k; split_index++)
        {
            Sum += need_check->at(end * k - 1 - split_index) * power;
            power *= 2;
        }
    }
    return Sum;
}

void AddingOverflowBit(BoolArray *Overflow_BoolArray, int k)
{
    int x = Overflow_BoolArray->size() - k;
    int sum_tmp = 0;
    {
        int power = 1;
        for (int split_index = 0; split_index < x; split_index++)
        {
            sum_tmp += Overflow_BoolArray->at(x - 1 - split_index) * power;
            power *= 2;
        }
    }
    {
        int power = 1;
        for (int split_index = x; split_index < Overflow_BoolArray->size(); split_index++)
        {
            sum_tmp += Overflow_BoolArray->at(Overflow_BoolArray->size() - 1 - split_index + x) * power;
            power *= 2;
        }
    }
    Overflow_BoolArray->fromInt(sum_tmp);
}

BoolArray *findChecksum(BoolArray *need_check, const int k)
{
    int Sum = getSplitSumNum(need_check, k, 0, 4);

    BoolArray *Sum_BoolArray = new BoolArray();
    Sum_BoolArray->fromInt(Sum);

    if (Sum_BoolArray->size() > k)
    {
        AddingOverflowBit(Sum_BoolArray, k);
    }

    if (Sum_BoolArray->size() < k)
    {
        BoolArray *temp_BoolArray = new BoolArray();
        for (int index = 0; index < k - Sum_BoolArray->size(); index++)
        {
            temp_BoolArray->add(0);
        }

        for (int index = 0; index < Sum_BoolArray->size(); index++)
        {
            temp_BoolArray->add(Sum_BoolArray->at(index));
        }
        delete Sum_BoolArray;
        Sum_BoolArray = temp_BoolArray;
    }

    for (int index = 0; index < Sum_BoolArray->size(); index++)
    {
        Sum_BoolArray->changeData(index, (Sum_BoolArray->at(index) == true) ? false : true);
    }
    return Sum_BoolArray;
}

BoolArray *checkReceiverChecksum(BoolArray *ReceivedMessage, const int k, BoolArray *Checksum)
{
    int Sum = getSplitSumNum(ReceivedMessage, k, 0, 4) + Checksum->toInt() * 2;
    BoolArray *Sum_BoolArray = new BoolArray();
    Sum_BoolArray->fromInt(Sum);

    if (Sum_BoolArray->size() > k)
    {
        AddingOverflowBit(Sum_BoolArray, k);
    }

    for (int index = 0; index < Sum_BoolArray->size(); index++)
    {
        Sum_BoolArray->changeData(index, (Sum_BoolArray->at(index) == true) ? false : true);
    }
    return Sum_BoolArray;
}
