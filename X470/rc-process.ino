
void MotorControl() {  //---------------------------MOTOR CONTROLS--------------------------------

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