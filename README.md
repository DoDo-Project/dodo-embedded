## ✨ 임베디드 주요 기능 (Key Embedded Features)

DoDo의 임베디드 시스템은 **Master-Slave 2보드 구조**로 설계되어, 웨어러블 폼팩터에서 GPS 위치 정보와 생체/활동 데이터를 동시에 수집합니다.

-   **✅ 실시간 센서 데이터 수집 (Real-time Sensor Data Acquisition)**
    > Slave 보드(ESP32)가 BMI160(가속도), MAX30102(심박)를 I2C로 폴링하여 실시간 수집합니다. <br> Master 보드(XIAO nRF52840 Sense)는 NEO-M8N GPS로 위치 데이터를 병렬로 수집합니다.

-   **✅ Master-Slave 통신 (Master-Slave Link)**
    > Slave에서 수집한 가속도/심박 데이터를 마그네틱 포고핀 커넥터를 통해 UART(단방향)로 Master에 전송합니다. <br> Master는 수신한 센서 데이터에 자체 GPS 좌표를 결합하여 하나의 패킷으로 구성합니다.

-   **✅ 데이터 전송 (Data Transmission)**
    > Master는 결합된 데이터를 BLE를 통해 DoDo 앱(dodo-app)으로 전송하며, 앱이 백엔드 서버로 업로드하는 구조입니다.

-   **✅ 전원 관리 (Power Management)**
    > XIAO nRF52840 Sense 내장 충전 IC(BQ25100)를 통해 LiPo 배터리를 직접 충전 관리합니다. <br> Slave 보드는 별도 배터리 없이 포고핀을 통해 Master로부터 전원을 공급받습니다.

<br>

## ⚙️ 기술 스택 (Tech Stack)

<div align="center">

### Embedded & Communication
<p>
<img src="https://img.shields.io/badge/Seeed%20XIAO%20nRF52840%20Sense-6E44FF?style=for-the-badge&logo=seeedstudio&logoColor=white">
<img src="https://img.shields.io/badge/ESP32-E7352C?style=for-the-badge&logo=espressif&logoColor=white">
<img src="https://img.shields.io/badge/UART-000000?style=for-the-badge">
<img src="https://img.shields.io/badge/I2C-000000?style=for-the-badge">
<img src="https://img.shields.io/badge/BLE_5.0-0082FC?style=for-the-badge&logo=bluetooth&logoColor=white">
</p>

### Sensors
<p>
<img src="https://img.shields.io/badge/NEO--M8N_GPS-4CAF50?style=for-the-badge">
<img src="https://img.shields.io/badge/BMI160_IMU-FF9800?style=for-the-badge">
<img src="https://img.shields.io/badge/MAX30102_HR-F44336?style=for-the-badge">
</p>

### Programming Languages
<p>
<img src="https://img.shields.io/badge/C/C++-00599C?style=for-the-badge&logo=c&logoColor=white">
<img src="https://img.shields.io/badge/Arduino-00979D?style=for-the-badge&logo=arduino&logoColor=white">
</p>

</div>

<br>

## 🤖 임베디드 설계 아키텍처 (Embedded System Architecture)

Master(XIAO nRF52840 Sense)와 Slave(ESP32) 2보드로 구성되며, 마그네틱 포고핀 커넥터로 물리적으로 결합/분리됩니다.

<!-- TODO: 아키텍처 다이어그램 추가 -->



**포고핀 커넥터 (4핀)**

| 핀 | 신호 |
| :--- | :--- |
| 1 | VCC (3.3V, Master → Slave) |
| 2 | GND |
| 3 | GND |
| 4 | DATA (Slave TX → Master RX, UART) |

<br>

## 🤝 Conventions
우리 프로젝트는 원활한 협업을 위해 아래와 같은 규칙을 따릅니다.

- **[Commit Convention](./.github/COMMIT_CONVENTION.md)**

<br>

## 📊 센서 자료 출처 (Sensor Source)

👉🏻 **[Pet Behavior Recognition Dataset using Wearable Sensors (MDPI)](https://www.mdpi.com/1424-8220/21/13/4510)**

<br>

## 💁‍♂️ 팀원 소개 (Team Members)

<table align="center">
  <tr>
    <td align="center">
      <a href="https://github.com/right-path-ptj">
      <img src="https://github.com/right-path-ptj.png?size=150" alt="박태정 프로필"/><br>
      <b>박태정</b>
    </td>
    <td align="center">
      <a href="https://github.com/anmincheol-71">
      <img src="https://github.com/anmincheol-71.png?size=150" alt="안민철 프로필"/><br>
      <b>안민철</b>
    </td>
  </tr>
</table>
