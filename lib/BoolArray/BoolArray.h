//
// Created by IDK on 2022/8/5
//

#ifndef BOOLARRAY_H
#define BOOLARRAY_H
#include <LinkedList.h>
#include <Arduino.h>
#include <string.h>

class BoolArray : public LinkedList<bool>
{
private:
public:
    BoolArray(/* args */);
    BoolArray(String &input_string);
    ~BoolArray();
    int toInt();
    bool at(int index);
    void fromString(String &input_string);
    void fromInt(int num);
    void changeData(int index, bool data);
    void disPlay();
};

#endif