
void PwmInit() {
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
#endif

  //  pwm.printDebug();   //  extra debug for ESP32 Analogwrite library
}