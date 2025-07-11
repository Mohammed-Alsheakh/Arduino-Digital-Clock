#include <LiquidCrystal.h>
const int rs = 12, en = 13, d4 = 7, d5 = 6, d6 = 5, d7 = 4;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
int saat = 10, dakika = 57, saniye = 50, a = 0, b = 0,c=0, modedayim = 0, sntodk = 0, dktost=0, sn=0;
unsigned long int millisonceki;

void setup() {
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  Serial.begin(9600);
  lcd.begin(16, 2);
  millisonceki = millis();
  unsigned long int millisonceki();
}

void loop() {
  if (digitalRead(2) == 1) {
    Serial.println("2 butonn basildi");
  }
  if (digitalRead(3) == 1) {
    Serial.println("3 butonn basildi");
  }


  while (millis() < millisonceki + 1000) {
    if(digitalRead(2) == 1 && modedayim == 1 && sntodk != 1 && dktost != 1)
      saniye = -1;
    }
  millisonceki = millis();
  Serial.println(millisonceki);
  saniye++;
  if (saniye == 60) {
    saniye = 0;
    dakika++;
  }
  if (dakika == 60) {
    dakika == 0;
    saat++;
    }
   if (saat == 24)
    saat = 0;
    
  
  lcd.setCursor(0, 0);
  if (saat < 10) {
    Serial.print("0");
    lcd.print("0");
  }
  Serial.print(saat);
  Serial.print(":");
  lcd.print(saat);
  lcd.print(":");
  if (dakika < 10) {
    Serial.print("0");
    lcd.print("0");
  }
  Serial.print(dakika);
  Serial.print(":");
  lcd.print(dakika);
  lcd.print(":");
  if (saniye < 10) {
    Serial.print("0");
    lcd.print("0");
  }
  Serial.println(saniye);
  lcd.print(saniye);

  if (digitalRead(2) == 1 && modedayim == 0) {
    a++;
    lcd.setCursor(0, 1);
    lcd.print(a);
  }
  if (digitalRead(2) == 0 && modedayim == 0) {
    a = 0;
    lcd.setCursor(0, 1);
    lcd.print("  ");
  }
  if (a == 3) {
    modedayim = 1;
    a = 0;
    /*if(digitalRead(2) == 0)
     sanal=1;
    else{
     delay(500);
     sanal=0;
    }*/
  }
  /*if(saniye>59) {
    saniye = 0;
    }
    else {
    Serial.println(saniye);
    }*/
  if(modedayim == 1) {
    lcd.setCursor(0, 1);
    lcd.print("modedayim");
    if(sntodk != 1 && digitalRead(3) == 0 && dktost != 1 || sn ==1) {
    lcd.setCursor(6, 0);
    lcd.print("  ");
    delay(200);
    lcd.setCursor(6, 0);
    lcd.print(saniye);
    delay(200);
    }
    if (digitalRead(3) == 1) {
      sntodk = 1;
      sn=0;
      b++;
      lcd.setCursor(11, 1);
      lcd.print(b);
    }
    if (digitalRead(3) == 0 && b != 0) {
      b = 0;
      lcd.setCursor(11, 1);
      lcd.print("  ");
    }
    if (b == 3) {
      sntodk = 0;
      b = 0;
      lcd.setCursor(0, 1);
      lcd.print("modeden ciktim   ");
      delay(1000);
      lcd.setCursor(0, 1);
      lcd.print("              ");
      modedayim = 0;
    }
    
     
    if(sntodk == 1) {
     if(digitalRead(2))
       dakika++;
     lcd.setCursor(3, 0);
     lcd.print("  ");
     delay(100);
     lcd.setCursor(3, 0);
     if(dakika<10)
       lcd.print("0");
     lcd.print(dakika);
     delay(100);
     if(dakika==59) {
       dakika = 0;
       saat++;
     }
    }
     if (digitalRead(3) == 1 && sntodk == 1) {
      dktost = 1;
      c++;
      lcd.setCursor(11, 1);
      lcd.print(c);
      lcd.setCursor(13, 1);
      lcd.print("h");
    }
    if (digitalRead(3) == 0 && c != 0 ) {
      c = 0;
      lcd.setCursor(11, 1);
      lcd.print("   ");
    }
      

    if(dktost == 1) {
      sntodk=0;
      if(digitalRead(2))
       saat++;
       lcd.setCursor(0, 0);
     lcd.print("  ");
     delay(100);
     lcd.setCursor(0, 0);
     if(saat<10)
       lcd.print("0");
     lcd.print(saat);
     delay(100);
     if(saat==24)
       saat = 0;

     if(digitalRead(3) == 1) {
      dktost = 0;
      sn = 1;
      }
      }
    
  }//if(modedayim == 1)
  Serial.println(modedayim);

}