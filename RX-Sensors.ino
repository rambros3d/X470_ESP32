//==================================================================

//---------------------RX Config for SBUS---------------------------
#ifdef SBUS
HardwareSerial SBUSS(1);
bfs::SbusRx sbus_rx(&SBUSS, RXpin, 17, RXinverted);
bfs::SbusData data;

#define sbusMin 172
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

void SensorSetup() {

  vinsens.attach(VSensPin);

#ifdef ADVANCED_HYDRAULICS
  adcAttachPin(BoomSensorPin);
  adcAttachPin(ArmSensorPin);
  adcAttachPin(BucketSensorPin);
#endif
}


int16_t PrevBoomPos = 0;
int16_t PrevArmPos = 0;
int16_t PrevBucketPos = 0;

void ReadSensors() {
  //----------------------Sensor Readings------------------------------
  Voltage = vinsens.readMiliVolts();
  Voltage = Voltage * Vmultiplier;

#ifdef ADVANCED_HYDRAULICS
  BoomPos = analogRead(BoomSensorPin);
  ArmPos = analogRead(ArmSensorPin);
  BucketPos = analogRead(BucketSensorPin);

  int16_t SensorRes = 1200;
  BoomPos = map(BoomPos, 1010, 2990, 0, SensorRes);
  ArmPos = map(ArmPos, 886, 2874, 0, SensorRes);
  BucketPos = map(BucketPos, 920, 2930, 0, SensorRes);

  BoomPos = constrain(BoomPos, 0, SensorRes);
  ArmPos = constrain(ArmPos, 0, SensorRes);
  BucketPos = constrain(BucketPos, 0, SensorRes);

  BoomSpeed = RateOfChange(BoomPos, 3);
  ArmSpeed = RateOfChange(ArmPos, 2);
  BucketSpeed = RateOfChange(BucketPos, 1);

  BoomSpeed = constrain(BoomSpeed, 0, SensorRes);
  ArmSpeed = constrain(ArmSpeed, 0, SensorRes);
  BucketSpeed = constrain(BucketSpeed, 0, SensorRes);

  PrevBoomPos = BoomPos;
  PrevArmPos = ArmPos;
  PrevBucketPos = BucketPos;
#endif

#ifdef SENSOR_DEBUG

  Serial.print("\n");
  Serial.print("Sensor Values:");
  Serial.print("\t");
  Serial.print(BoomPos);
  Serial.print("\t");
  Serial.print(ArmPos);
  Serial.print("\t");
  Serial.print(BucketPos);
  Serial.print("\t");
  Serial.print(Voltage);
  Serial.print("\t");
  Serial.println(Pressure);

  Serial.print("Rate of change  ");
  Serial.print("Boom:");
  Serial.print(BoomSpeed);
  Serial.print("\t");
  Serial.print("Arm:");
  Serial.print(ArmSpeed);
  Serial.print("\t");
  Serial.print("Bucket:");
  Serial.println(BucketSpeed);
#endif
}