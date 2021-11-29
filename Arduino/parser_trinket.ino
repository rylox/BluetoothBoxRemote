#include <SoftSerial_INT0.h>
#include "TrinketHidCombo.h"

#define P_RX 2                        // Reception PIN (SoftSerial)
#define P_TX 1                        // Transmition PIN (SoftSerial)

SoftSerial esp32Serial(P_RX, P_TX);
int command = 0;
int presses = 3;

void setup(){
  
 esp32Serial.begin(9600);
 TrinketHidCombo.begin();
 delay(200);
 TrinketHidCombo.pressMultimediaKey(MMKEY_VOL_DOWN);
}

void loop(){
    while(esp32Serial.available()){
      
      command = esp32Serial.read();
      switch(command){
        case 85:  //ASCII code for U
          for(int i = 0; i < presses; i++) {
             TrinketHidCombo.pressMultimediaKey(MMKEY_VOL_UP);
             delay(100);
          }
          break;
        case 68:  //ASCII code for D
          for(int i = 0; i < presses; i++) {
             TrinketHidCombo.pressMultimediaKey(MMKEY_VOL_DOWN);
             delay(100);
          }
          break;          
        default:
          break;    
      }     
       delay(5);
       TrinketHidCombo.poll();
    }
}
