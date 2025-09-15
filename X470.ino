#include "user-config.h"  //  modify this file to trim valve midpoints

#include <pwmWrite.h>  //  https://github.com/Dlloydev/ESP32-ESP32S2-AnalogWrite
#include "sbus.h"      //  https://github.com/bolderflight/sbus
#include <IBusBM.h>    //  https://github.com/bmellink/IBusBM/

//-------------------------DEBUGGING--------------------------------------------------
#define SERVO_DEBUG  //  Shows Servo & ESC PWM outputs
//#define RX_DEBUG  //  Shows RX channels from Receiver
//#define SENSOR_DEBUG    //  Shows Hall Sensor and Voltage Values
//#define ADVANCED_DEBUG  // Show Modes and Valve Controls

Pwm pwm = Pwm();  // pwm setup for ESC & Servo
TaskHandle_t coreTask1;
TaskHandle_t coreTask2;

#include "board_config.h"
#include "rx-inputs.h"
#include "pwm-outputs.h"

void setup() {
  Serial.begin(115200);

  xTaskCreatePinnedToCore(core1Task, "Core 1 Task", 10000, NULL, 1, &coreTask1, 0);
  xTaskCreatePinnedToCore(core2Task, "Core 2 Task", 10000, NULL, 1, &coreTask2, 1);
}

void core1Task(void* parameter) {
  RXsetup();
  for (;;) {
    ReadRX();
    delay(10);
  }
}

void core2Task(void* parameter) {
  PwmInit();  // Function to Start Servo in Safe Position
  for (;;) {
    PumpControl();
    HydraulicControl();
    MotorControl();
    PwmOutput();
    delay(50);
  }
}

void loop() {
}