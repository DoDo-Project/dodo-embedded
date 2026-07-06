#ifndef MASTER_PINS_H
#define MASTER_PINS_H

// GPS (NEO-M8N) - SoftwareSerial
#define GPS_RX_PIN D0  // GPS TXD -> 수신
#define GPS_TX_PIN D1  // GPS RXD <- 송신 (모듈 설정 안 하면 미사용)
#define GPS_BAUD 9600

// Slave 링크 (포고핀) - 하드웨어 UART(Serial1), XIAO 기본 핀 D6(TX)/D7(RX) 그대로 사용
#define SLAVE_LINK_BAUD 115200

#endif
