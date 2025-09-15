//==================================================================

//----------------------SERVO CONTROLS------------------------------
// Valid range is 0-180 (degrees) or 544-2400 (microseconds)
// 1000 - 2000 us is suitable for Blheli_S & Blheli32 configured ESCs

#define EscMinUs 1000
#define EscMidUs 1500
#define EscMaxUs 2000

#define PumpMax 1500  //  Range is from 0 to 2000

// Likewise the valve should be fully open when servo hits the endpoint range
// Servo Range is (Midpoint - Valverange) to (Midpoint + ValveRange)
#define ValveRange 45

// The Valve should be closed when the Servo Angle is in the mid position
#define BoomValveMid 75
#define ArmValveMid 90
#define BucketValveMid 90
#define ClawValveMid 90
#define RotatorValveMid 90

//==================================================================
//---------------------PIN DEFINITIONS------------------------------

// Define pin number for the hydraulic pump
#define PumpPin E1

// Define pin numbers servo valves and extra controls
#define SwingPin E2

// Define pin numbers for the left and right travel motors
#define TravelLeftPin E3
#define TravelRightPin E4


#define BoomPin S1
#define ArmPin S2
#define BucketPin S3

#define RXpin AUX1
#define RXinverted false  //  ESP32 supports both Inverted and Non-Inv signals

#define TXpin AUX2

#define BOARD_LED L1
