#include <Wire.h>
#include "MAX30105.h"
#include "heartRate.h"

#define BMI160_ADDR 0x69
#define BMI160_CMD 0x7E
#define BMI160_ACC_X_L 0x12

MAX30105 particleSensor;

// ---------------- BMI160 ----------------

void writeRegister(uint8_t reg, uint8_t data)
{
  Wire.beginTransmission(BMI160_ADDR);
  Wire.write(reg);
  Wire.write(data);
  Wire.endTransmission();
}

uint8_t readRegister(uint8_t reg)
{
  Wire.beginTransmission(BMI160_ADDR);
  Wire.write(reg);
  Wire.endTransmission(false);

  Wire.requestFrom(BMI160_ADDR, (uint8_t)1);

  if (Wire.available())
    return Wire.read();

  return 0;
}

void readBytes(uint8_t reg, uint8_t *buffer, uint8_t len)
{
  Wire.beginTransmission(BMI160_ADDR);
  Wire.write(reg);
  Wire.endTransmission(false);

  Wire.requestFrom(BMI160_ADDR, len);

  for (int i = 0; i < len; i++)
  {
    if (Wire.available())
      buffer[i] = Wire.read();
  }
}

// -----------------------------------------

void setup()
{
  Serial.begin(115200);
  Wire.begin(21, 22);

  Serial.println("Initializing...");

  // MAX30102
  if (!particleSensor.begin(Wire))
  {
    Serial.println("MAX30102 not found");
    while (1);
  }

  particleSensor.setup();
  Serial.println("MAX30102 OK");

  // BMI160
  uint8_t chipID = readRegister(0x00);

  Serial.print("BMI160 Chip ID = 0x");
  Serial.println(chipID, HEX);

  if (chipID != 0xD1)
  {
    Serial.println("BMI160 not found");
    while (1);
  }

  writeRegister(BMI160_CMD, 0x11); // accel normal mode
  delay(100);

  writeRegister(BMI160_CMD, 0x15); // gyro normal mode
  delay(100);

  Serial.println("BMI160 OK");
}

void loop()
{
  // ---------- MAX30102 ----------
  long irValue = particleSensor.getIR();

  if (checkForBeat(irValue))
  {
    Serial.print("Beat Detected");
  }

  // ---------- BMI160 ----------
  uint8_t data[12];

  readBytes(BMI160_ACC_X_L, data, 12);

  int16_t ax = (int16_t)((data[1] << 8) | data[0]);
  int16_t ay = (int16_t)((data[3] << 8) | data[2]);
  int16_t az = (int16_t)((data[5] << 8) | data[4]);

  int16_t gx = (int16_t)((data[7] << 8) | data[6]);
  int16_t gy = (int16_t)((data[9] << 8) | data[8]);
  int16_t gz = (int16_t)((data[11] << 8) | data[10]);

  // ---------- 출력 ----------
  Serial.print(" IR=");
  Serial.print(irValue);

  Serial.print(" | ACC(");
  Serial.print(ax);
  Serial.print(",");
  Serial.print(ay);
  Serial.print(",");
  Serial.print(az);
  Serial.print(")");

  Serial.print(" | GYRO(");
  Serial.print(gx);
  Serial.print(",");
  Serial.print(gy);
  Serial.print(",");
  Serial.print(gz);
  Serial.println(")");

  delay(50);
}