#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Deklarasikan terlebih dahulu LCD, LED, SDA dan SCL pin
LiquidCrystal_I2C lcd(0x27, 16, 2);
int LED_Merah = D1;
int LED_Hijau = D2;
int SDA_pin = D4;
int SCL_pin = D3;

void setup()
{ // Atur LED sebagai output, kemudian inisialisasi untuk lcdnya menggunakan begin
    pinMode(LED_Merah, OUTPUT);
    pinMode(LED_Hijau, OUTPUT);
    Wire.begin(SDA_pin, SCL_pin);
    lcd.begin(16, 2);
    lcd.init();
    lcd.backlight();
}

void loop()
{ // Disini mengatur agar LED merah menyala dan LED Hijau Mati kemudian menulis tulisan LED Merah pada LCD dan ini berlangsung selama 5 detik
    digitalWrite(LED_Merah, HIGH);
    digitalWrite(LED_Hijau, LOW);
    lcd.clear();
    lcd.print("LED Merah");
    delay(5000);

    // Disini mengatur agar LED Hijau menyala dan LED Merah Mati kemudian menulis tulisan LED Hijau pada LCD dan ini berlangsung selama 5 detik
    digitalWrite(LED_Merah, LOW);
    digitalWrite(LED_Hijau, HIGH);
    lcd.clear();
    lcd.print("LED Hijau");
    delay(5000);
}
