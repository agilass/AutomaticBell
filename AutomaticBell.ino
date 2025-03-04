#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "uRTCLib.h"
// Set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x27, 16, 2);
//LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE); // Addr, En, Rw, Rs, d4, d5, d6, d7, backlighpin, polarity

// uRTCLib rtc;
uRTCLib rtc(0x68);
char daysOfTheWeek[7][12] = {"DIM", "LUN", "MAR", "MER", "JEU", "VEN", "SAM"};

int Year;
int Month;
int Day;
int Day_of_week;
int Hour;
int Min;
int Sec;
int period;
int in1 = 8; 
int activate=0;

void setup()
{
    Serial.begin(9600);
    lcd.init();
    lcd.clear();
    lcd.backlight();
  
    lcd.setCursor(4,1);
    lcd.print("WELCOME !");
    digitalWrite(in1, HIGH); // pour que relais 5v ne fonctionne pas 
    delay(3000); // wait for console opening\
      // Comment out below line once you set the date & time.
  // Following line sets the RTC with an explicit date & time
  // for example to set January 13 2022 at 12:56 you would call:
//   rtc.set(0, 50, 20, 2, 14, 11, 22);
  // rtc.set(second, minute, hour, dayOfWeek, dayOfMonth, month, year)
//   set day of week (1=Sunday, 7=Saturday)
    URTCLIB_WIRE.begin();
    pinMode(8, OUTPUT);
    // Setup LCD to 16x2 characters
}

void loop()
{//start loop
    // Display time on the right conrner upper line
    rtc.refresh();
    lcd.clear();
    Hour = rtc.hour()-1;
    Min = rtc.minute();
    Sec = rtc.second();
    Day = rtc.day();
    Day_of_week =rtc.dayOfWeek()-1;
    Month = rtc.month();
    Year = rtc.year();
    
    lcd.print(daysOfTheWeek[rtc.dayOfWeek()-1]);
    //Display Period Number
    lcd.setCursor(6, 0);
    if(Day < 10){lcd.print("0");}lcd.print(Day);lcd.print('/');
    if(Month < 10){lcd.print("0");}lcd.print(Month);lcd.print('/');lcd.print("20");lcd.print(rtc.year());
    lcd.setCursor(0, 1);
    if(Hour < 10){lcd.print("0");}lcd.print(Hour);lcd.print(':');
    if(Min < 10){lcd.print("0");}lcd.print(Min);lcd.print(':');
    if(Sec < 10){lcd.print("0");}lcd.print(Sec);
//    température 
    lcd.setCursor(12, 1);
    lcd.print(rtc.temp()  / 100);
    lcd.print((char)223);
    lcd.print('C');
    
    jour_son(Day_of_week);
    delay(1000);
}//end loop

 void son(int H,int M){
  if (H== Hour && M== Min && Sec<= 8){
    digitalWrite(in1, LOW);
    delay(8000);
    digitalWrite(in1, HIGH);
    Serial.println("motor is running");
//    Serial.println(Day_of_week);
    }
    }

//     void jour_son(int jour){
//       if(jour == 0){  // dimanche 
//       }
//       else if(jour == 1){       // lundi
// //        son(12,58); // _________TEST___________________
//         son(13,45);
//         son(13,55);
//         son(14,55);
//         son(15,55);
//         son(16,5);
//         son(17,0);
//         son(18,0); 
//         }
//       else if(jour == 5 || jour == 6){ // vendredi et samdi
//         son(8,15);
//         son(8,25);
//         son(9,25);
//         son(10,25);
//         son(10,35);
//         son(11,30);
//         son(12,30);
//         }
//         else{
//         son(8,15);
//         son(8,25);
//         son(9,25);
//         son(10,25);
//         son(10,35);
//         son(11,30);
//         son(12,30);
// //     ===========================
//         son(13,45);
//         son(13,55);
//         son(14,55);
//         son(15,55);
//         son(16,5);
//         son(17,0);
//         son(18,0); 
//           }
//---------------------------------------------------ramadane--------------------------------------------------------------
          void jour_son(int jour){//start jour_son
      if(jour == 0){  // dimanche 
      }
      else if(jour == 1){       // lundi
//        son(12,58); // _________TEST___________________
        son(12,15);
        son(12,30);
        son(13,15);
        son(13,20);
        son(14,5);
        son(14,15);
        son(15,0);
        son(15,5);
        son(15,50); 
        }
      else if(jour == 5){ // vendredi 
        son(8,15);
        son(8,30);
        son(9,15);
        son(9,20);
        son(10,5);
        son(10,15);
        son(11,0);
        son(11,5);
        son(11,50);
        }
      else if(jour == 6){ //  samdi
        son(8,25);
        son(8,40);
        son(9,25);
        son(9,30);
        son(10,15);
        son(10,25);
        son(11,10);
        son(11,15);
        son(12,0);
        }

      else{
        son(8,25);
        son(8,40);
        son(9,25);
        son(9,30);
        son(10,15);
        son(10,25);
        son(11,10);
        son(11,15);
        son(12,0);
//     ===========================
        son(12,15);
        son(12,30);
        son(13,15);
        son(13,20);
        son(14,5);
        son(14,15);
        son(15,0);
        son(15,5);
        son(15,50); 
          }
          }//end jour_son
      
      
      