#include <GyverEncoder.h> // CLK 2, DW 3, SW 10, BTN1 7, BTN2 8, OUT 5, motor 6,
#include <HID-Project.h>
// #include <HID-Settings.h>
#define CLK 2
#define DT 3
#define SW 10

#include "GyverEncoder.h"
Encoder enc1(CLK, DT, SW);

// int value = 0;
// int ledPin = 6;                 // мотор подключен к выходу 6


void setup() {
   Serial.begin(9600);
  enc1.setType(TYPE1);        // тип энкодера TYPE1 одношаговый, TYPE2 двухшаговый. Если ваш энкодер работает странно, смените тип\=
  enc1.setFastTimeout(5);    // таймаут на скорость isFastR. По умолч. 50
  Consumer.begin();
    digitalWrite(6, HIGH);
    delay(1000);
    digitalWrite(6, LOW);
     digitalWrite(5, HIGH);
    delay(500);
    digitalWrite(5, LOW);
  
}

void loop() {
   // обязательная функция отработки. Должна постоянно опрашиваться
  enc1.tick();

  if (enc1.isRightH()) { //  value++;        // если был поворот направо, увеличиваем на 1
  Consumer.write(MEDIA_VOLUME_UP);  
  // digitalWrite(9, HIGH);
   delay(50);
  // digitalWrite(9, LOW);
  }
  if (enc1.isLeftH()) { // value--;         // если был поворот налево, уменьшаем на 1
  Consumer.write(MEDIA_VOLUME_DOWN); 
   // digitalWrite(9, HIGH);
    delay(50);
   // digitalWrite(9, LOW);
   }

   if (enc1.isRight()) {
      Consumer.write(MEDIA_VOLUME_UP);
      Consumer.write(MEDIA_VOLUME_UP);
      Consumer.write(MEDIA_VOLUME_UP);
      Consumer.write(MEDIA_VOLUME_UP);
      Consumer.write(MEDIA_VOLUME_UP);
      Consumer.write(MEDIA_VOLUME_UP);
      Consumer.write(MEDIA_VOLUME_UP);
      Consumer.write(MEDIA_VOLUME_UP);
      Consumer.write(MEDIA_VOLUME_UP);
      Consumer.write(MEDIA_VOLUME_UP);  // value += 5;    // если было удержание + поворот направо, увеличиваем на 5
      delay(50);
   }
   if (enc1.isLeft()) { // value -= 5;     // если было удержание + поворот налево, уменьшаем на 5
      Consumer.write(MEDIA_VOLUME_DOWN);
      Consumer.write(MEDIA_VOLUME_DOWN);    
      Consumer.write(MEDIA_VOLUME_DOWN);
      Consumer.write(MEDIA_VOLUME_DOWN);    
      Consumer.write(MEDIA_VOLUME_DOWN);
      Consumer.write(MEDIA_VOLUME_DOWN);
      Consumer.write(MEDIA_VOLUME_DOWN);
      Consumer.write(MEDIA_VOLUME_DOWN);    
      Consumer.write(MEDIA_VOLUME_DOWN);
      Consumer.write(MEDIA_VOLUME_DOWN);
      delay(50);
   }
   if (enc1.isFastR()) { // value += 10;    // если был быстрый поворот направо, увеличиваем на 10
      Consumer.write(MEDIA_VOLUME_UP);
      Consumer.write(MEDIA_VOLUME_UP);
      Consumer.write(MEDIA_VOLUME_UP);
      Consumer.write(MEDIA_VOLUME_UP);
  //    Consumer.write(MEDIA_VOLUME_UP);
  //   digitalWrite(9, HIGH);
      delay(50);
   // digitalWrite(9, LOW);
     }
    if (enc1.isFastL()) { // value -= 10;    // если был быстрый поворот налево, уменьшаем на 10
      Consumer.write(MEDIA_VOLUME_DOWN);
      Consumer.write(MEDIA_VOLUME_DOWN);
      Consumer.write(MEDIA_VOLUME_DOWN);
      Consumer.write(MEDIA_VOLUME_DOWN);
   //   Consumer.write(MEDIA_VOLUME_DOWN);
   // digitalWrite(9, HIGH);
      delay(50);
  //  digitalWrite(9, LOW);
     }
  // if (enc1.isTurn()) {                // если был совершён поворот (индикатор поворота в любую сторону)
   // digitalWrite(9, HIGH);
   // delay(150);
   // digitalWrite(9, LOW);
   //  Serial.println(value);            // выводим значение при повороте
  // }
  
 if (digitalRead(7)) { // change to if (!digitalRead(7)) { if you want it to be active on a low signal
    // Serial.write(111111);
    Consumer.write(MEDIA_PLAY_PAUSE);
    // Keyboard.press(KEY_LEFT_GUI);
    // Keyboard.press('d');
    // Keyboard.releaseAll();
   // digitalWrite(6, HIGH);
     delay(200);
  //  digitalWrite(6, LOW);
 //    digitalWrite(5, HIGH);
 //   delay(500);
 //   digitalWrite(5, LOW);
    }
 if (digitalRead(8)) { // change to if (!digitalRead(8)) { if you want it to be active on a low signal
    Consumer.write(MEDIA_VOLUME_MUTE);
    digitalWrite(6, HIGH);
    delay(300);
    digitalWrite(6, LOW);
    // digitalWrite(5, HIGH);
    // delay(500);
    // digitalWrite(5, LOW);
  } 
  if (enc1.isPress())  {
  Consumer.write(MEDIA_PLAY_PAUSE); 
  delay(200); }
 /* if (digitalRead(10)) { 
    Keyboard.press(KEY_LEFT_GUI);
    Keyboard.press('d');
    Keyboard.releaseAll();
    digitalWrite(6, HIGH);
    delay(500);
    digitalWrite(6, LOW);
     digitalWrite(5, HIGH);
    delay(500);
    digitalWrite(5, LOW);
 } */
}
