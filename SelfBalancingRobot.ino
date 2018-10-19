#include <PID_v1.h>
#include <Wire.h>
#include <Kalman.h>


/* Assign a unique ID to this sensor at the same time */
//Adafruit_ADXL345_Unified accel = Adafruit_ADXL345_Unified(12345);

Kalman kalman;

//Define Variables we'll be connecting to
double Setpoint, Input, Output, CurrentAngle;

//double p = 0.1, i = 0, d = 0;

//Specify the links and initial tuning parameters
//PID myPID(&Input, &Output, &Setpoint, p, i, d, REVERSE);

void setup(void)
{
  Serial.begin(9600);
  //  Serial.begin(115200);
  

  InitMotors();
  InitGyro();
  // SetupUltrasonicSensor();

  // Input = 0;
  // Setpoint = 1;

  //turn the PID on
  // myPID.SetMode(AUTOMATIC);
  // myPID.SetOutputLimits(-50, 50);
  // myPID.SetSampleTime(200);
  // myPID.SetTunings(p, i, d);

  // kalman.setAngle(Input);
}

void loop(void)
{
  CurrentAngle = ReadMPU();
  Input = CurrentAngle;
 
  
   // Input = kalman.getAngle(Input, 8, 1);
   // Serial.println(Input);
    
 // RunMotors(Input, Input);
  //  GetDistanceToObstacle();

}
