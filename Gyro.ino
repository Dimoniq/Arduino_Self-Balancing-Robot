#include "MPU6050.h"

#define sampleTime  0.01  
int16_t accY, accZ, gyroX;


#define Kp  3
#define Kd  0.0001
#define Ki  2
#define targetAngle 0.5

volatile float accAngle, gyroAngle, currentAngle, prevAngle = 0, error, prevError = 0, errorSum = 0;
volatile int gyroRate, motorPower;
MPU6050 mpu;
void InitGyro() {
  mpu.initialize();
  mpu.setYAccelOffset(2400);
  mpu.setZAccelOffset(963);
  mpu.setXGyroOffset(30);
}

double ReadMPU() {
  accY = mpu.getAccelerationY();
  accZ = mpu.getAccelerationZ();
  gyroX = mpu.getRotationX();

  accAngle = atan2(accY, accZ) * RAD_TO_DEG;
  gyroRate = map(gyroX, -32768, 32767, -250, 250);
  gyroAngle = (float)gyroRate * sampleTime;
  currentAngle = 0.9934 * (prevAngle + gyroAngle) + 0.0066 * (accAngle);
  Serial.println(currentAngle); 
  //Serial.print(" ");
error = currentAngle - targetAngle;
  errorSum = errorSum + error;  
  errorSum = constrain(errorSum, -300, 300);
  //calculate output from P, I and D values
  motorPower = Kp*(error) + Ki*(errorSum)*sampleTime - Kd*(currentAngle-prevAngle)/sampleTime;
  prevAngle = currentAngle;
//  Serial.println(motorPower);
  return motorPower;
}
