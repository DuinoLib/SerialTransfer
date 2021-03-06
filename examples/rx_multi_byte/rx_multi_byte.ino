#include "SerialTransfer.h"


SerialTransfer myTransfer;

struct STRUCT {
  char z;
  float y;
} testStruct;


void setup()
{
  Serial.begin(115200);
  Serial1.begin(115200);
  myTransfer.begin(Serial1);
}


void loop()
{
  if(myTransfer.available())
  {
    myTransfer.rxObj(testStruct);
    Serial.print(testStruct.z);
    Serial.print(' ');
    Serial.println(testStruct.y);
    Serial.println();
  }
  else if(!myTransfer.status)
  {
    Serial.print("ERROR: ");

    if(myTransfer.status == CRC_ERROR)
      Serial.println(F("CRC_ERROR"));
    else if(myTransfer.status == PAYLOAD_ERROR)
      Serial.println(F("PAYLOAD_ERROR"));
    else if(myTransfer.status == STOP_BYTE_ERROR)
      Serial.println(F("STOP_BYTE_ERROR"));
  }
}

