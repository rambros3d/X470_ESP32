
void PwmInit() {
  pinMode(PWR_EN, OUTPUT);
  pinMode(OUT_EN, OUTPUT);
  //pinMode(BUCK_EN, OUTPUT);
  digitalWrite(PWR_EN, LOW);
  digitalWrite(OUT_EN, HIGH);
  //pinMode(BUCK_EN, HIGH);
  pwm.writeServo(TravelLeftPin, EscMidUs);
  pwm.writeServo(TravelRightPin, EscMidUs);
  pwm.writeServo(SwingPin, EscMidUs);
  pwm.writeServo(PumpPin, EscMinUs);
  pwm.writeServo(BoomPin, BoomValveMid);
  pwm.writeServo(ArmPin, ArmValveMid);
  pwm.writeServo(BucketPin, BucketValveMid);
}

void PwmOutput() {
  //---------------------------MOVEMENT ESC-------------------------------
  pwm.writeServo(TravelLeftPin, TrackLeftUs);
  pwm.writeServo(TravelRightPin, TrackRightUs);
  pwm.writeServo(SwingPin, SwingUs);

  //---------------------------HYDRAULIC CONTROLS------------------------------
  pwm.writeServo(PumpPin, PumpUs);
  pwm.writeServo(BoomPin, BoomValve);
  pwm.writeServo(ArmPin, ArmValve);
  pwm.writeServo(BucketPin, BucketValve);

#ifdef SERVO_DEBUG
  Serial.print("\n");
  Serial.print("Valves:");
  Serial.print("\t");
  Serial.print(BoomValve);
  Serial.print("\t");
  Serial.print(ArmValve);
  Serial.print("\t");
  Serial.print(BucketValve);
  Serial.print("\t");

  Serial.print("ESC:");
  Serial.print("\t");
  Serial.print(TrackLeftUs);
  Serial.print("\t");
  Serial.print(TrackRightUs);
  Serial.print("\t");
  Serial.print(SwingUs);
  Serial.print("\t");
  Serial.println(PumpUs);

  //pwm.printDebug();   //  extra debug for ESP32 Analogwrite library
#endif
}

//---------------------------MOTOR CONTROLS--------------------------------
void MotorControl() {

  TrackLeftUs = map(RXchannel[LeftChannel], RXmin, RXmax, EscMinUs, EscMaxUs);
  TrackRightUs = map(RXchannel[RightChannel], RXmin, RXmax, EscMinUs, EscMaxUs);
  SwingUs = map(RXchannel[SwingChannel], RXmin, RXmax, EscMinUs, EscMaxUs);
}

void HydraulicControl() {

  BoomValve = RXchannel[BoomChannel];
  ArmValve = RXchannel[ArmChannel];
  BucketValve = RXchannel[BucketChannel];

  BoomValve = map(BoomValve, RXmin, RXmax, BoomValveMid - ValveRange, BoomValveMid + ValveRange);
  ArmValve = map(ArmValve, RXmin, RXmax, ArmValveMid - ValveRange, ArmValveMid + ValveRange);
  BucketValve = map(BucketValve, RXmin, RXmax, BucketValveMid - ValveRange, BucketValveMid + ValveRange);
}

void PumpControl() {

  int16_t ReqPower = abs(RXchannel[BoomChannel]) * 5 + abs(RXchannel[ArmChannel]) * 4 + abs(RXchannel[BucketChannel]) * 3;
  ReqPower = ReqPower / 10 - 100;

  PumpUs = map(ReqPower, 0, 1000, EscMinUs, PumpMax);
  PumpUs = constrain(PumpUs, EscMinUs, PumpMax);

  if (RXchannel[EnableChannel] < 500) {
    PumpUs = EscMinUs;
  }
}