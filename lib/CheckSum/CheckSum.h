//
// Created by IDK on 2022/8/5.
//
#ifndef CHECKSUM_CHECKSUM_H
#define CHECKSUM_CHECKSUM_H
#include "CheckSum.h"
#include <Arduino.h>
#include <LinkedList.h>
#include <BoolArray.h>

BoolArray *findChecksum(BoolArray *need_check, const int k);
BoolArray *checkReceiverChecksum(BoolArray *ReceivedMessage, const int k, BoolArray *Checksum);

#endif