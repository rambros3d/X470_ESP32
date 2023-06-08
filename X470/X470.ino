
#include "default_config.h"
#include <pwmWrite.h>         //  https://github.com/Dlloydev/ESP32-ESP32S2-AnalogWrite
#include "sbus.h"             //  https://github.com/bolderflight/sbus
#include <ESP32AnalogRead.h>  //  https://github.com/madhephaestus/ESP32AnalogRead

#define SBUS
#define ADVANCED_HYDRAULICS  // Closed Loop Hydraulic control using Hall Sensors

//-------------------------DEBUGGING--------------------------------------------------
//#define SERVO_DEBUG     //  Shows Servo & ESC PWM outputs
//#define RX_DEBUG  //  Shows RX channels from Receiver
#define SENSOR_DEBUG    //  Shows Hall Sensor and Voltage Values
//#define ADVANCED_DEBUG  // Show Modes and Valve Controls

//-------------------------Servo Outputs---------------------------------------------
int16_t TrackLeftUs = 0;
int16_t TrackRightUs = 0;
int16_t SwingUs = 0;

int16_t BoomValve = 0;
int16_t ArmValve = 0;
int16_t BucketValve = 0;

int16_t ClawValve = 0;
int16_t RotatorUs = 0;

int16_t PumpUs = 0;

//--------------------------------------------------------------------------
int16_t RXchannel[17];  //  Organized values from 0 to 2000
#define RXmin -1000
#define RXmax 1000

bool HydraulicEn = 0;

int8_t HydraulicMode = 1;  //  Different Modes for Advanced hydraulics
int8_t PumpMode = 1;       //  Modes to control Pump Motor Automatically
//--------------------------------------------------------------------------
int16_t Voltage = 0;

int16_t BoomPos = 0;
int16_t ArmPos = 0;
int16_t BucketPos = 0;

int16_t BoomSpeed = 0;
int16_t ArmSpeed = 0;
int16_t BucketSpeed = 0;

int16_t Pressure = 0;

Pwm pwm = Pwm();

TaskHandle_t Task1;
TaskHandle_t Task2;

void setup() {
  // Dual Core Setup
  xTaskCreatePinnedToCore(Process1, "InputOutputs", 10000, NULL, 1, &Task1, 0);
  delay(100);
  xTaskCreatePinnedToCore(Process2, "Processor", 10000, NULL, 1, &Task2, 1);
  delay(100);
}

//==========================================================================

void Process1(void* pvParameters) {

  RXsetup();
  SensorSetup();

  for (;;) {

    ReadRX();
    ReadSensors();
    delay(50);
  }
}

void Process2(void* pvParameters) {

  PwmInit();  // Function to Start Servo in Safe Position

  Serial.begin(115200);
  Serial.println("Hydraulic Excavator Controller");

  for (;;) {

    PwmOutput();
    HydraulicControl();
    PumpControl();
    delay(10);
  }
}

void loop() {}
//==========================================================================