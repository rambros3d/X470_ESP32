//==================================================================

//---------------------RX Config for SBUS---------------------------
#ifdef SBUS
HardwareSerial SBUSS(1);
bfs::SbusRx sbus_rx(&SBUSS, RXpin, 17, RXinverted);
bfs::SbusData data;

#define sbusMin 174
#define sbusMax 1811
#endif

//------------------------------------------------------------------
void RXsetup() {

#ifdef SBUS
  sbus_rx.Begin();
#endif
}
//------------------------------------------------------------------
void ReadRX() {

#ifdef SBUS
  if (sbus_rx.Read()) {
    data = sbus_rx.data();  // Read and Organize the received data

    for (uint8_t i = 1; i <= 10; i++) {
      RXchannel[i] = map(data.ch[i - 1], sbusMin, sbusMax, RXmin, RXmax);
      RXchannel[i] = constrain(RXchannel[i], RXmin, RXmax);
    }

#ifdef RX_DEBUG
    /* Display the received data */
    for (uint8_t i = 1; i <= 12; i++) {
      //Serial.print(data.ch[i-1]);
      Serial.print(RXchannel[i]);
      Serial.print("\t");
    }
    Serial.println(data.NUM_CH);
#endif
  }
#endif
}

//==================================================================
ESP32AnalogRead vinsens;

#ifdef ADVANCED_HYDRAULICS
ESP32AnalogRead boomsens;
ESP32AnalogRead armsens;
ESP32AnalogRead bucketsens;
#endif
ESP32AnalogRead pressuresens;

void SensorSetup() {

  vinsens.attach(VSensPin);

#ifdef ADVANCED_HYDRAULICS
  boomsens.attach(BoomSensorPin);
  armsens.attach(ArmSensorPin);
  bucketsens.attach(BucketSensorPin);
#endif
}
void ReadSensors() {
  //----------------------Sensor Readings------------------------------
  Voltage = vinsens.readMiliVolts();
  Voltage = Voltage * Vmultiplier;

#ifdef ADVANCED_HYDRAULICS
  BoomPos = boomsens.readMiliVolts();
  ArmPos = armsens.readMiliVolts();
  BucketPos = bucketsens.readMiliVolts();

  BoomPos = map(BoomPos, 0, 3300, 0, 90);
  ArmPos = map(ArmPos, 0, 3300, 0, 90);
  BucketPos = map(BucketPos, 0, 3300, 0, 90);
#endif

#ifdef SENSOR_DEBUG
  Serial.print(Voltage);
  Serial.print("\t");
  Serial.print(BoomPos);
  Serial.print("\t");
  Serial.print(ArmPos);
  Serial.print("\t");
  Serial.print(BucketPos);
  Serial.print("\t");
  Serial.println(Pressure);
#endif
}