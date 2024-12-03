/***************************************************************
   Motor driver function definitions - by James Nugen
   *************************************************************/

#ifdef L298_MOTOR_DRIVER
  #define M2_SPEED_ENABLE	      14
  #define M2_MOTOR_BACKWARD     16
  #define M2_MOTOR_FORWARD      18

  #define M1_SPEED_ENABLE	      13
  #define M1_MOTOR_BACKWARD     22
  #define M1_MOTOR_FORWARD      23  //19
  #define FORWARD               1
  #define BACKWARD              0

  #define PING_LED              27
#endif

// void initMotorController();
void setMotorSpeed(int enable_spd_pin, int forward_pin, int backward_pin, int speed);
// void setMotorSpeeds(int leftSpeed, int rightSpeed);
