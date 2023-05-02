
//---------------------------Calculate Rate of change ---------------------------

float RateOfChange(int16_t currentValue, int16_t valueID) {
  static int16_t previousValue[10] = { 0 };
  static unsigned long previousTime[10] = { 0 };

  // calculate the time difference between the current and previous measurement
  unsigned long timeInterval = millis() - previousTime[valueID];

  // calculate the difference between the current and previous value
  int16_t valueDifference = currentValue - previousValue[valueID];

  // calculate the rate of change by dividing the value difference by the time interval
  float rateOfChange = (float)valueDifference / (float)timeInterval * 100;

  // update the previous value and time for the next calculation
  previousValue[valueID] = currentValue;
  previousTime[valueID] = millis();

  return rateOfChange;
}


// Function to calculate servo angle from current and target velocity

int16_t ReqSpeed(int16_t TargetVelocity, int16_t CurrentVelocity, int16_t MaxError) {
  int16_t Error = TargetVelocity - CurrentVelocity;                // Calculate error
  int16_t Output = map(Error, -MaxError, MaxError, RXmin, RXmax);  // Map error to output range
  return Output;                                                   // Return output value
}
