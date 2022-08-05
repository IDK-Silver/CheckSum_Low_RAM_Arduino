#include "BoolArray.h"

BoolArray::BoolArray(String &input_string)
{
    fromString(input_string);
}

BoolArray::BoolArray(/* args */)
{
}

BoolArray::~BoolArray()
{
}

int BoolArray::toInt()
{
    int sum = 0;
    int power = 1;
    for (int index = 0; index < this->size(); index++)
    {
        sum += this->get(this->size() - 1 - index) * power;
        power *= 2;
    }
    return sum;
}

void BoolArray::fromString(String &input_string)
{
    for (auto &c : input_string)
    {
        this->add(c - '0');
    }
}

bool BoolArray::at(int index)
{
    return this->getNode(index)->data;
};

void BoolArray::fromInt(int num)
{
    this->clear();
    LinkedList<bool> rev_temp;
    int index = 0;
    while (num > 0)
    {
        rev_temp.add(num % 2);
        num = num / 2;
        index++;
    }
    for (int rev_index = index - 1; rev_index >= 0; rev_index--)
    {
        // Serial.print(rev_temp.get(rev_index));
        // Serial.print(" ");
        this->add(rev_temp.get(rev_index));
    }

    rev_temp.clear();
}

void BoolArray::changeData(int index, bool data)
{
    this->set(index, data);
}

void BoolArray::disPlay()
{
    for (int index = 0; index < this->size(); index++)
    {
        Serial.print(this->at(index));
    }
    Serial.println();
};