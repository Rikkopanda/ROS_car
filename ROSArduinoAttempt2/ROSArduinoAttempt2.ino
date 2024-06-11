#define USE_BASE

#ifdef USE_BASE
 /* L298 Motor driver*/
 #define L298_MOTOR_DRIVER
 /* The Pololu MC33926 dual motor driver shield */
 //#define POLOLU_MC33926

#endif

#define BAUDRATE 57600

#include <string.h>
#include <stdlib.h>
#include <Arduino.h>
#include "commands.h"
#include "motor_driver.h"
#include "esp32-hal-ledc.h"
#include "driver/ledc.h"

void setup()
{
	Serial.begin(BAUDRATE);
	Serial.println("Hello from esp32\n");
	int	freq = 20000;
	int	resolution = 8;

	pinMode(PING_LED, OUTPUT);
	// pinMode(M2_MOTOR_FORWARD, OUTPUT);
	// pinMode(M1_MOTOR_BACKWARD, OUTPUT);
	// pinMode(M1_MOTOR_FORWARD, OUTPUT);
	Ping("Start up Esp32");
	// Turn off motors - Initial state
	// digitalWrite(M2_MOTOR_BACKWARD, LOW);
	// digitalWrite(M2_MOTOR_FORWARD, LOW);
	// digitalWrite(M1_MOTOR_BACKWARD, LOW);
	// digitalWrite(M1_MOTOR_FORWARD, LOW);
	// attach the channel to the GPIO to be controlled
	ledcAttach(M1_SPEED_ENABLE, freq, resolution);
}

void Ping(String ping_message)
{
	Serial.println(ping_message);
	digitalWrite(PING_LED, HIGH);
	delay(400);
	digitalWrite(PING_LED, LOW);
	delay(400);
	digitalWrite(PING_LED, HIGH);
	delay(400);
	digitalWrite(PING_LED, LOW);
	delay(400);
	digitalWrite(PING_LED, HIGH);
	delay(400);
	digitalWrite(PING_LED, LOW);
	delay(400);
}


void init_args(char args[3][32])
{
  	for(int i=0; i<3; i++)
	{
      for (int j = 0; j < 32; j++)
        args[i][j] = '\0';
    }
}

char args[3][32];

void runCommand()
{
	char	cmd = args[0][0];
	int		arg1_l = atoi(args[1]);
	int		arg2_l = atoi(args[2]);
  	Serial.printf("num arg 1:%d 2:%d\n", arg1_l, arg2_l);
	switch(cmd) {
	case ANALOG_READ:
		// Serial.println(analogRead(arg1_ref));
		break;
	case DIGITAL_READ:
		// Serial.println(digitalRead(arg1_ref));
		break;
	case ANALOG_WRITE:
		// analogWrite(arg1_ref, arg2_ref);
		// Serial.println("OK"); 
		break;
	case PING:
		Ping("'Hello ping received!'");
		break;
	case MOTOR_RAW_PWM:
		Serial.printf("sending raw PWM");
		setMotorSpeed(M1_SPEED_ENABLE, M2_MOTOR_FORWARD, M2_MOTOR_BACKWARD, arg1_l);
		break;
	default:
		Serial.println("Invalid command");
  }
}

void loop()
{
	char byteRead;

	init_args(args);
	int j = 0;
	int i = 0;
	while (Serial.available() > 0)
	{
		byteRead = Serial.read();
		// Serial.print(byteRead);
		if (byteRead == ' ')
		{
			j++;
			i = 0;
			continue;
		}
		args[j][i] = byteRead;
		i++;
		delay(10);// Serial.available() needs time to be able to register new characters.
	}

	// Serial.printf("___________\ncurrent arg_i :%d \t index :%d \n", g_arg_index, g_index);
	if (args[0][0] != '\0')
  	{
		Serial.printf("\n_________\n");
		for (int j = 0; j < 3; j++)
		{
		Serial.printf("i=%d: %s\n", j, args[j]);
		// Serial.printf("hello\n");
		}
      delay(10);
      runCommand();
      delay(10);
		// resetCommand();
  	}

}