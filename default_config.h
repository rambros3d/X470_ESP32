//==================================================================

//------------------------Set Channels--------------------------------------
#define BucketChannel 1
#define ArmChannel 2
#define BoomChannel 3
#define SwingChannel 4

#define LeftChannel 7   //  Left Travel
#define RightChannel 8  //  Right Channel

#define ClawChannel 9      //  Optional Channel for Claw
#define RotatorChannel 10  // Optional Channel for Rotation

#define EnableChannel 5  //  Hydraulic Safety Channel

#define HydraulicCh 10  //  Three way switch
#define PumpCh 6        //  Three way swtch

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

// The Valve should be closed when the Servo Ang---e is in the mid position
#define BoomValveMid 75
#define ArmValveMid 90
#define BucketValveMid 90
#define ClawValveMid 90
#define RotatorValveMid 90

//==================================================================
//---------------------PIN DEFINITIONS------------------------------

// Define pin numbers for the left and right travel motors
#define TravelLeftPin 27
#define TravelRightPin 14

// Define pin numbers servo valves and extra controls
#define SwingPin 12
#define BoomPin 16
#define ArmPin 17
#define BucketPin 18

#define ClawPin 23
#define RotatorPin 19

// Define pin number for the hydraulic pump
#define PumpPin 4

#define VSensPin 35      //  Voltage Sense Pin
#define Vmultiplier 4.0  // Multiplier value for voltage divider

#define RXpin 22
#define RXinverted false  //  ESP32 supports both Inverted and Non-Inv signals

//====================================================================
//---------------------Advanced Controls------------------------------
// Define pin numbers for the hall sensors (optional)
#define BoomSensorPin 36
#define ArmSensorPin 39
#define BucketSensorPin 34
