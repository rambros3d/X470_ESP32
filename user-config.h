//----------------------SERVO CONTROLS------------------------------

// EDIT these 3 values to set the midpoint of the valve
// The Valve should be closed when the Servo Angle is in the mid position
#define BoomValveMid 90
#define ArmValveMid 90
#define BucketValveMid 90



// Likewise the valve should be fully open when servo hits the endpoint range
// Servo Range is (Midpoint - Valverange) to (Midpoint + ValveRange)
#define ValveRange 45


// 1000 - 2000 us is suitable for Blheli32 & AM32 configured ESCs
#define EscMinUs 1000
#define EscMidUs 1500
#define EscMaxUs 2000

#define PumpMax 1500  //  Range is from 0 to 2000


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

//--------------------------------------------------------------------------
