#include <Arduino.h>

#define SENSOR_PIN 34  // فرض می‌کنیم یک سنسور به پین 34 متصل است

void setup() {
  Serial.begin(115200);  // ارتباط سریال با نرخ 115200
  randomSeed(analogRead(0));  // برای تولید اعداد تصادفی بهتر
}

void loop() {
  // تولید داده‌های تصادفی برای دما، رطوبت و فشار
  float temperature = random(15, 35) + random(0, 100) / 100.0;  // دما از 15 تا 35 درجه سانتیگراد
  float humidity = random(30, 80)+ random(0, 100) / 100.0;  // رطوبت از 30% تا 80%
  float pressure = random(1000, 1025) + random(0, 100) / 100.0;  // فشار از 1000 تا 1025 hPa

  // ارسال داده‌ها به کامپیوتر به صورت قالب‌بندی شده
  Serial.print("Temperature: ");
  Serial.println(temperature);
  Serial.print("Humidity: ");
  Serial.println(humidity);
  Serial.print("Pressure: ");
  Serial.println(pressure);

  delay(1000);  // هر ثانیه یکبار داده جدید ارسال می‌شود
}