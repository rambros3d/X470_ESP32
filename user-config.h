//-------------------------RX Settings-------------------------------------

uint8_t RXprotocol = 3;  //  1=SBUS, 2=SBUS_INVERTED, 3=IBUS, 4=PPM
uint8_t BucketChannel = 1;
uint8_t ArmChannel = 2;
uint8_t BoomChannel = 3;
uint8_t SwingChannel = 4;
uint8_t LeftChannel = 7;      //  Left Travel
uint8_t RightChannel = 8;     //  Right Channel
uint8_t ClawChannel = 9;      //  Optional Channel for Claw
uint8_t RotatorChannel = 10;  // Optional Channel for Rotation
uint8_t EnableChannel = 5;
uint8_t PumpCh = 6;

//-------------------------Servo Outputs-------------------------------------
int16_t TrackLeftUs = 0;
int16_t TrackRightUs = 0;
int16_t SwingUs = 0;
int16_t PumpUs = 0;

int16_t BoomValve = 0;
int16_t ArmValve = 0;
int16_t BucketValve = 0;

//--------------------------------------------------------------------------
int16_t RXchannel[17];  //  Organize input range from -1000 to 1000
const int16_t RXmin = -1000;
const int16_t RXmax = 1000;

bool HydraulicEn = 0;

int8_t HydraulicMode = 1;  //  Different Modes for Advanced hydraulics
int8_t PumpMode = 1;       //  Modes to control Pump Motor Automatically
//--------------------------------------------------------------------------

int16_t Voltage = 0;

//----------------------------Hydraulics--------------------------------------
int16_t BoomPos = 0;
int16_t ArmPos = 0;
int16_t BucketPos = 0;

int16_t BoomSpeed = 0;
int16_t ArmSpeed = 0;
int16_t BucketSpeed = 0;

int16_t Pressure = 0;