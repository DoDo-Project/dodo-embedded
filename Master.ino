#include <SoftwareSerial.h>
#include <TinyGPSPlus.h>
#include "MasterPins.h"

SoftwareSerial gpsSerial(GPS_RX_PIN, GPS_TX_PIN);
TinyGPSPlus gps;

void setup()
{
  Serial.begin(115200);            // USB 디버그
  Serial1.begin(SLAVE_LINK_BAUD);  // Slave 링크 (포고핀, D6/D7)
  gpsSerial.begin(GPS_BAUD);       // GPS (D0/D1)

  Serial.println("Master ready");
}

void loop()
{
  // GPS 스트림 파싱
  while (gpsSerial.available())
  {
    gps.encode(gpsSerial.read());
  }

  // Slave에서 한 줄(ax,ay,az,gx,gy,gz,ir,beat) 수신되면 GPS와 합쳐서 출력
  if (Serial1.available())
  {
    String line = Serial1.readStringUntil('\n');

    Serial.print(line);

    if (gps.location.isValid())
    {
      Serial.print(",");
      Serial.print(gps.location.lat(), 6);
      Serial.print(",");
      Serial.println(gps.location.lng(), 6);
    }
    else
    {
      Serial.println(",NA,NA");
    }
  }
}
