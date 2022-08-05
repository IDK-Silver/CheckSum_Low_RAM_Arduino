#include <Arduino.h>
#include <string.h>
#include <LinkedList.h>
#include <CheckSum.h>
#include <BoolArray.h>

void setup()
{
	Serial.begin(9600);
}

void loop()
{
	int k = 8;
	String *SentMessage = new String(F("10010101011000111001010011101100"));
	BoolArray *SentMessage_BoolArray = new BoolArray(*SentMessage);
	delete SentMessage;

	BoolArray *Checksum = findChecksum(SentMessage_BoolArray, k);
	delete SentMessage_BoolArray;

	// String *ReceivedMessage = new String("10000101011000111001010011101101");
	String *ReceivedMessage = new String(F("10010101011000111001010011101100"));
	BoolArray *ReceivedMessage_BoolArray = new BoolArray(*ReceivedMessage);
	BoolArray *ReceiverChecksum = checkReceiverChecksum(ReceivedMessage_BoolArray, k, Checksum);
	delete ReceivedMessage;

	Serial.print(F("SENDER SIDE CHECKSUM:  "));
	Checksum->disPlay();

	Serial.print(F("RECEIVER SIDE CHECKSUM:  "));
	ReceiverChecksum->disPlay();

	BoolArray *finalsum = new BoolArray();
	finalsum->fromInt(Checksum->toInt() + ReceiverChecksum->toInt());
	delete Checksum;
	delete ReceiverChecksum;

	BoolArray *finalcomp = new BoolArray();
	for (int index = 0; index < finalsum->size(); index++)
	{
		finalcomp->add((finalsum->at(index) == true) ? false : true);
	}
	delete finalsum;

	if (finalcomp->toInt() == 0)
	{
		Serial.println(F("Receiver Checksum is equal to 0. Therefore,"));
		Serial.println(F("STATUS: ACCEPTED"));
	}
	else
	{
		Serial.println(F("Receiver Checksum is not equal to 0. Therefore,"));
		Serial.println(F("STATUS: ERROR DETECTED"));
	}

	delete finalcomp;
	Serial.println(F("------------------------------------------------"));
	delay(1500);
}