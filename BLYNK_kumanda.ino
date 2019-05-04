
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#ifndef UNIT_TEST
#include <Arduino.h>
#include <IRremoteESP8266.h>
#include <IRsend.h>
#include <SPI.h>
#endif
BlynkTimer timer;
IRsend irsend(5);             // An IR LED is controlled by GPIO pin 5 (D1)

#define BLYNK_PRINT Serial

#define tus1 0x................    // 0x'dan sonraki kısma kendi Kumandandan tespit ettiğin bir tuşun kodunu buraya yaz 
#define tus2 0x................    // 0x'dan sonraki kısma kendi Kumandandan tespit ettiğin bir tuşun kodunu buraya yaz 
#define tus3 0x................    // 0x'dan sonraki kısma kendi Kumandandan tespit ettiğin bir tuşun kodunu buraya yaz 
#define tus4 0x................    // 0x'dan sonraki kısma kendi Kumandandan tespit ettiğin bir tuşun kodunu buraya yaz  


char auth[] = "................";     // Kendi BLYNK TOKEN'ini buraya yaz


// Kendi WiFi Bilgilerini buraya yaz
char ssid[] = "..............";
char pass[] = "..............";


int sanalbuton1;          // V1   - Blynk Uygulamasında buton koy ve V1 seç
int sanalbuton2;          // V2   - Blynk Uygulamasında buton koy ve V2 seç
int sanalbuton3;          // V3   - Blynk Uygulamasında buton koy ve V3 seç
int sanalbuton4;          // V4   - Blynk Uygulamasında buton koy ve V4 seç


int sayici = 5;



void setup()
{
  irsend.begin();
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
  timer.setInterval(100L, butonpressed);
  timer.setInterval(1000L, butonnopressed);
  Blynk.connect();
}




BLYNK_WRITE(V1)
{
  sanalbuton1 = param.asInt();
  if (sanalbuton1 == 1)
  {
    butonpressed ();
  }

  else
  {
    butonnopressed ();
  }
}



BLYNK_WRITE(V2)
{
  sanalbuton2 = param.asInt();
  if (sanalbuton2 == 1)
  {
    butonpressed ();
  }

  else
  {
    butonnopressed ();
  }
}



BLYNK_WRITE(V3)
{
  sanalbuton3 = param.asInt();
  if (sanalbuton3 == 1)
  {
    butonpressed ();
  }

  else
  {
    butonnopressed ();
  }
}




BLYNK_WRITE(V4)
{
  sanalbuton4 = param.asInt();
  if (sanalbuton4 == 1)
  {
    butonpressed ();
  }

  else
  {
    butonnopressed ();
  }
}




void butonpressed ()
{
  if (sanalbuton1 )
  {
    sayici = 1;
    while (sanalbuton1 == HIGH && sayici > 0)
    {
      sayici--;
    }
    sayici = 0;
    irsend.sendNEC(tus1, 32);        // Burada sendNEC kısmına kendi kumanda kodunda tespit ettiğin türü, parantez içindeki kısımdaki rakama ise kendi kumanda kodunda tespit ettiği bit sayısını yaz
    delay(10);
  }


  if (sanalbuton2)
  {
    sayici = 1;
    while (sanalbuton2 == HIGH && sayici > 0)
    {
      sayici--;
    }
    sayici = 0;
    irsend.sendNEC(tus2, 32);
    delay (100);
  }


  if (sanalbuton3)
  {
    sayici = 1;
    while (sanalbuton3 == HIGH && sayici > 0)
    {
      sayici--;
    }
    sayici = 0;
    irsend.sendNEC(tus3, 32);
    delay (100);
  }

  if (sanalbuton4)
  {
    sayici = 1;
    while (sanalbuton4 == HIGH && sayici > 0)
    {
      sayici--;
    }
    sayici = 0;
    irsend.sendNEC(tus4, 32);
  }

}



void butonnopressed ()
{
  sayici = 0;
}



void loop()
{
  Blynk.run();
  timer.run();
}
