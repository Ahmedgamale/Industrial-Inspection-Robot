#include <Wire.h>
#include <Adafruit_MLX90614.h>
#include <RTClib.h>
#include <LiquidCrystal_I2C.h>

#define SDA_PIN 21
#define SCL_PIN 22

#define MLX_CHANNEL 0
#define RTC_CHANNEL 1
#define LCD_CHANNEL 2

Adafruit_MLX90614 mlx;
RTC_DS3231 rtc;
LiquidCrystal_I2C lcd(0x27, 16, 2);


void tcaSelect(uint8_t channel) {
  if (channel > 7) return;
  Wire.beginTransmission(0x70);
  Wire.write(1 << channel);
  Wire.endTransmission();
}

void setup() {
  Serial.begin(115200);
  delay(2000);

  Wire.begin(SDA_PIN, SCL_PIN);
  Serial.println("ESP32 + TCA + MLX + RTC + LCD");

  // -------- LCD INIT (Channel 2) --------
  tcaSelect(LCD_CHANNEL);
  lcd.init();
  lcd.backlight();
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("System Booting");

  // -------- RTC INIT (Channel 1) --------
  tcaSelect(RTC_CHANNEL);
  delay(100);
  if (!rtc.begin()) {
    Serial.println("❌ RTC NOT FOUND");
    lcd.setCursor(0, 1);
    lcd.print("RTC ERROR");
    while (1);
  }
  Serial.println("✅ RTC READY");


  // -------- MLX INIT (Channel 0) --------
  tcaSelect(MLX_CHANNEL);
  delay(100);
  if (!mlx.begin()) {
    Serial.println("❌ MLX NOT FOUND");
    lcd.setCursor(0, 1);
    lcd.print("MLX ERROR");
    while (1);
  }
  Serial.println("✅ MLX READY");

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("System Ready");
  delay(1500);
  lcd.clear();
}

void loop() {
  // ---- temp readings  ----
  tcaSelect(MLX_CHANNEL);
  float objTemp = mlx.readObjectTempC();

  // ----  time readings ----
  tcaSelect(RTC_CHANNEL);
  DateTime now = rtc.now();

  Serial.print("Temp: ");
  Serial.print(objTemp);
  Serial.print(" C | Time: ");
  Serial.print(now.hour());
  Serial.print(":");
  Serial.print(now.minute());
  Serial.print(":");
  Serial.println(now.second());

  // ----  LCD ----
  tcaSelect(LCD_CHANNEL);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print(objTemp, 1);
  lcd.print(" C");

  lcd.setCursor(0, 1);
  if (now.hour() < 10) lcd.print("0");
  lcd.print(now.hour());
  lcd.print(":");
  if (now.minute() < 10) lcd.print("0");
  lcd.print(now.minute());
  lcd.print(":");
  if (now.second() < 10) lcd.print("0");
  lcd.print(now.second());

  delay(1000);
}
