
#ifdef USE_BASE
   
 #ifdef POLOLU_VNH5019

 #elif defined L298_MOTOR_DRIVER

	void setMotorSpeed(int enable_spd_pin, int forward_pin, int backward_pin, int speed) {
		unsigned char reverse = 0;


		Serial.printf("speed: %d\n", speed);
		if (speed < 0)
		{
			speed = -speed;
			reverse = 1;
		}
		if (speed > 255)
			speed = 255;
		if (reverse == 0)
		{
			digitalWrite(forward_pin, HIGH);
			digitalWrite(backward_pin, LOW);
		}
		else
		{
			digitalWrite(forward_pin, LOW);
			digitalWrite(backward_pin, HIGH);
		}
		ledcWrite(enable_spd_pin, speed);
	}
 #else
  #error A motor driver must be selected!
 #endif


#endif