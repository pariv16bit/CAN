#include <ACAN_T4.h>
#include <ACAN_T4_Settings.h>
#include <CANMessage.h>

ACAN_T4_Settings settings (500 * 1000) ;
CANMessage message ;

void setup() {
  pinMode (LED_BUILTIN, OUTPUT) ;
  Serial.begin (9600) ;
  while (!Serial) {
    delay (50) ;
    digitalWrite (LED_BUILTIN, !digitalRead (LED_BUILTIN)) ;
  }
  Serial.println ("CAN1-CAN2-CAN3 test") ;
  Serial.print ("Bit rate: ") ;
  Serial.print (settings.actualBitRate ()) ;
  Serial.println (" bit/s") ;
  settings.mTxPinIsOpenCollector = true ;
  settings.mRxPinConfiguration = ACAN_T4_Settings::PULLUP_22k ;
  uint32_t errorCode = ACAN_T4::can1.begin (settings) ;
  if (0 == errorCode) {
    Serial.println ("can1 ok") ;
  }else{
    Serial.print ("Error can1: 0x") ;
    Serial.println (errorCode, HEX) ;
  }
  message.id = 0x125;
  delay (2) ;
}

void loop() {
  a = ACAN_T4::can1.receive (message);
  Serial.println(a);
}
