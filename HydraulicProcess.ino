
void HydraulicControl() {
  HydraulicMode = map(RXchannel[BoomChannel], RXmin, RXmax, 1, 3);

  switch (HydraulicMode) {
    case 1:  //---------------------------Manual Valve mode----------------------------------
      BoomValve = RXchannel[BoomChannel];
      ArmValve = RXchannel[ArmChannel];
      BucketValve = RXchannel[BucketChannel];
      break;

    case 2:  //---------------------------Closed Loop Velocity mode---------------------------
      int16_t MaxSpeed = 300;
      BoomValve = ReqSpeed(RXchannel[BoomChannel] / 5, BoomSpeed, MaxSpeed);

      break;
  }
  BoomValve = map(BoomValve, RXmin, RXmax, BoomValveMid - ValveRange, BoomValveMid + ValveRange);
  ArmValve = map(BoomValve, RXmin, RXmax, ArmValveMid - ValveRange, ArmValveMid + ValveRange);
  BucketValve = map(BoomValve, RXmin, RXmax, BucketValveMid - ValveRange, BucketValveMid + ValveRange);
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