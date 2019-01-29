/* @file Keypad.ino
|| @version 1.1
|| @author Heejoong
|| ## 2018-08-09 ~
*/
#include <Keyboard.h>

const byte ROWS = 4;  //four rows
const byte COLS = 4;  //four columns

//define keypad
uint8_t keyPad[ROWS][COLS] = {
  {'l','k','j','h'}, //1
  {'i','u','y','t'}, //0
  {'m','n','c',KEY_RETURN}, //2
  {KEY_LEFT_ALT,KEY_LEFT_CTRL,'x','z'}  //3
};
byte aPin[ROWS] = {A0, A1, A9, A10}; //connect to the row pin
byte dPin[COLS] = {0 ,1 ,2 ,3}; //connect to the col pin

void setup() {
  Serial.begin(9600);
  Keyboard.begin();
  for(char a = 0 ;a < 4 ;a++ ){
      pinMode(aPin[a], INPUT_PULLUP);
  }
  for(char d = 0 ;d < 4 ;d++ ){
      pinMode(dPin[d], OUTPUT);
  }
}

void loop() {
  for (char x = 0; x < 4; x++) {
    for(char y = 0; y < 4; y++) {
      digitalWrite(x, LOW);
      if (digitalRead(aPin[y])) Keyboard.release(keyPad[x][y]);
      else Keyboard.press(keyPad[x][y]);
      digitalWrite(x, HIGH);
    }
  }
}
