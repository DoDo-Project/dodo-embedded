#ifndef SLAVE_PINS_H
#define SLAVE_PINS_H

// I2C (BMI160, MAX30102 공유 버스)
#define I2C_SDA_PIN 21
#define I2C_SCL_PIN 22

// Master 링크 (포고핀, 하드웨어 UART2)
// 포고핀은 VCC/GND/GND/DATA 4핀이라 RX(GPIO16)는 실제로는 배선 안 됨 (미사용)
#define MASTER_LINK_RX_PIN 16  // 미사용
#define MASTER_LINK_TX_PIN 17  // Slave TX -> Master RX (D7)
#define MASTER_LINK_BAUD 115200

#endif
