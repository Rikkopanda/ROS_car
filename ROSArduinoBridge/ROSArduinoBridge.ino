
#define USE_BASE

#ifdef USE_BASE
 /* L298 Motor driver*/
 #define L298_MOTOR_DRIVER
 /* The Pololu MC33926 dual motor driver shield */
 //#define POLOLU_MC33926

#endif


#define BAUDRATE 9600
#include <string.h>
#include <stdlib.h>
#include "commands.h"
#include "motor_driver.h"
#include <Arduino.h>
#include "sensors.h"

char	read_chr = 0;
int		g_index = 0;
int		g_arg_index = 0;

typedef struct s_arg
{
	char	argv[16];
	long	argv_int;/* The arguments converted to integers */
} t_arg;

t_arg	g_args[3];
// long &g_cmd = g_args[0].argv_int;
// long &arg1_ref = g_args[1].argv_int;
// long &arg2_ref = g_args[2].argv_int;

void setup()
{
	Serial.begin(BAUDRATE);
	Serial.println("Hello from esp32\n");
	int ledChannel = 0;
	int	freq = 5000;
	int	resolution = 8;
  	g_arg_index = 0;

	ledcSetup(LEDC_CHANNEL, freq, resolution);
	// attach the channel to the GPIO to be controlled
	ledcAttachPin(ANALOG_TEST_CONTROL, LEDC_CHANNEL);

	// initMotorController();
}
// char argus[3][16];

String arguments;

void loop()
{
	read_chr = 0;
	while (Serial.available() > 0)
	{
    
		parse_args();
		// Serial.println("benshaud 1: ");

		// delay(1000);
  	}
	print_args();

    Serial.println("hello hello"); 
	if (read_chr == '\n' || read_chr == '\r')
	{
		runCommand();
		// delay(10);
		// resetCommand();
    // 	read_chr = 0;
	}
    delay(10);
	
  delay(1000);
}

/* Clear the current command parameters */
void resetCommand() {
	// g_cmd = 0;
  // Serial.println("resetCommand");
  // Serial.println(g_arg_index);

	// for (int i = 0; i < 3; i++)
	// {
	// 	// memset(g_args[g_arg_index].argv, 0, sizeof(g_args[g_arg_index].argv));
  //   	g_args[i].argv[0] = '\0';
	// }
	// g_index = 0;
	// g_arg_index = 0;
}

int runCommand(args[3][32])
{

  // g_cmd = g_args[0].argv[0];
  // g_args[0].argv_int = atoi(g_args[0].argv);
  // g_args[1].argv_int = atoi(g_args[1].argv);
	char cmd = args[0][0];
  // Serial.print("Command: ");
  // Serial.println(g_cmd);
  // for (int i = 0; i < 1; i++) {
  //     Serial.print("Arg ");
  //     Serial.print(i);
  //     Serial.print(": ");
  //     Serial.println(g_args[i].argv);
  //     Serial.print("Converted Arg ");
  //     Serial.print(i);
  //     Serial.print(": ");
  //     Serial.println(g_args[i].argv_int);
  // }
  Serial.println("after 1: ");

	switch(g_cmd) {
	case ANALOG_READ:
		Serial.println(analogRead(arg1_ref));
		break;
	case DIGITAL_READ:
		Serial.println(digitalRead(arg1_ref));
		break;
	case ANALOG_WRITE:
		analogWrite(arg1_ref, arg2_ref);
		Serial.println("OK"); 
		break;
	case PING:
		Serial.println(Ping(arg1_ref));
		break;
	case MOTOR_RAW_PWM:
		setMotorSpeeds(arg1_ref, arg2_ref);
		break;
	default:
		Serial.println("Invalid Command");
	}
    Serial.println("benshaud 1: ");

}

void print_args()
{
  Serial.printf("___________\ncurrent arg_i :%d \t index :%d \n", g_arg_index, g_index);
  for (int j = 0; j < 3; j++)
  {
    Serial.printf("str at i %d: %s\n", j, argus[j]);
    // Serial.printf("hello\n");
  }
}
int i = 0;
int j = 0;

void parse_args()
{
	for (int x = 0; x < 3; x++)
	{
		argus[x][0] = '\0';
		// g_args[x].argv_int = 0;
	}
	Serial.println("hello boss"); 
	read_chr = 0;
	i = 0;
	j = 0;
	while (read_chr != -1)
	{
		read_chr = Serial.read();
		Serial.print(read_chr); 
		if (read_chr == '\r' || read_chr == '\n' || read_chr == -1)
			break;
		if (read_chr == ' ')
		{
			i = 0;
			j++;
			if (j == 3)
				break;
			continue;
		}
		if (i < 16)
			argus[j][i] = read_chr;
		i++;
	}
}
