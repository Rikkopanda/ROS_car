/***************************************************************
   Motor driver function definitions - by James Nugen
   *************************************************************/

#ifdef L298_MOTOR_DRIVER
  #define M2_SPEED_ENABLE	      12
  #define M2_MOTOR_BACKWARD     33
  #define M2_MOTOR_FORWARD      32

  #define M1_SPEED_ENABLE	      13
  #define M1_MOTOR_BACKWARD     35
  #define M1_MOTOR_FORWARD      34
  #define FORWARD               1
  #define BACKWARD              0

  #define PING_LED              15
#endif

// void initMotorController();
void setMotorSpeed(int enable_spd_pin, int forward_pin, int backward_pin, int speed);
// void setMotorSpeeds(int leftSpeed, int rightSpeed);
