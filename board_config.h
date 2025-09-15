//==================================================================
//---------------------PIN MAPPING------------------------------

// Define pin number for the hydraulic pump
#define PumpPin E1

// Define pin number for swing motor
#define SwingPin E2

// Define pin numbers for the left and right travel motors
#define TravelLeftPin E3
#define TravelRightPin E4

// Define pin numbers servo valves
#define BoomPin S1
#define ArmPin S2
#define BucketPin S3

#define RXpin AUX1
#define RXinverted false  //  ESP32 supports both Inverted and Non-Inv signals

#define TXpin AUX2  // not used, just a dummy pin

#define BOARD_LED L1
