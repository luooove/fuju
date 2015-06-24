
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <dht11.h>
dht11 DHT11;
#define DHT11PIN 2
LiquidCrystal_I2C lcd(0x27,16,2);  // set the LCD address to 0x20 for a 16 chars and 2 line display
double temperature1,humidity1;
void setup()
{
  lcd.init();                      // initialize the lcd 

  // Print a message to the LCD.
  lcd.backlight();
  lcd.print("Hello, world!");
  Serial.begin(9600);
  Serial.println("DHT11 TEST PROGRAM ");
  Serial.print("LIBRARY VERSION: ");
  Serial.println(DHT11LIB_VERSION);
  Serial.println();
}

void temp()
{
    int chk = DHT11.read(DHT11PIN);
     switch (chk)
  {
    case DHTLIB_OK: 
                Serial.println("OK"); 
                break;
    case DHTLIB_ERROR_CHECKSUM: 
                Serial.println("Checksum error"); 
                break;
    case DHTLIB_ERROR_TIMEOUT: 
                Serial.println("Time out error"); 
                break;
    default: 
                Serial.println("Unknown error"); 
                break;
  }
  humidity1 = (float)DHT11.humidity;
  temperature1 = (float)DHT11.temperature;
  Serial.println((float)DHT11.humidity, 2);
  Serial.println((float)DHT11.temperature, 2);
}

void loop()
{
  temp();
  delay(1000);
  lcd.clear();                // LCD清屏
  lcd.print(humidity1);
  lcd.setCursor(8, 0);               // 定位LCD光标为第一行起始位置0，0（列在前，行在后）
  lcd.print(temperature1);
}
