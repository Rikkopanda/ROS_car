#define USE_BASE

#ifdef USE_BASE
 /* L298 Motor driver*/
 #define L298_MOTOR_DRIVER
 /* The Pololu MC33926 dual motor driver shield */
 //#define POLOLU_MC33926

#endif

// #define BAUDRATE 57600
#define BAUDRATE 9600

#include <string.h>
#include <stdlib.h>
#include <Arduino.h>
#include "commands.h"
#include "motor_driver.h"
#include "esp32-hal-ledc.h"
#include "driver/ledc.h"
#include <WiFi.h>
#include <PubSubClient.h>
#include "hal/wdt_hal.h"
#include "hal/ledc_types.h"

//wifi
WiFiClient      espClient;
// const char*     ssid = "V30_9620";
// const char*     password = "";
const char*     ssid = "Michiel de Router";
const char*     password = "943427963EC7";

//mqtt
PubSubClient  client(espClient); // creates a pub sub client 
const char    *mqtt_broker = "test.mosquitto.org";
const char    *motor_topic = "motor_command";
const char    *joy_stick_topic = "joy_stick_msg";
const char    *speed_topic = "speed_msg";
const char    *status_esp32_B = "status_esp32";
const char    *mqtt_username = NULL;
const char    *mqtt_password = NULL;
const int     mqtt_port = 1883;

float 		  speed_factor;
int 		  speed_setting;
char		  args[15][200];

void setup()
{
	Serial.begin(BAUDRATE);
	Serial.println("Hello from esp32\n");
	int	freq = 20000;
	int	resolution = 8;
	speed_setting = 0;
	speed_factor = 0;

	connect_wifi();
	connect_broker();

	client.publish(status_esp32_B, "Hi, I'm ESP32 B ^^");
	client.subscribe(motor_topic);
	client.subscribe(joy_stick_topic);
	client.subscribe(speed_topic);
  
	pinMode(PING_LED, OUTPUT);
	pinMode(M2_MOTOR_FORWARD, OUTPUT);
	pinMode(M2_MOTOR_BACKWARD, OUTPUT);
	pinMode(M1_MOTOR_FORWARD, OUTPUT);
	pinMode(M1_MOTOR_BACKWARD, OUTPUT);
	Ping("Start up Esp32");
	// Turn off motors - Initial state
	digitalWrite(M2_MOTOR_FORWARD, LOW);
	digitalWrite(M2_MOTOR_BACKWARD, LOW);
	digitalWrite(M1_MOTOR_FORWARD, LOW);
	digitalWrite(M1_MOTOR_BACKWARD, LOW);
	// attach the channel to the GPIO to be controlled
	// ledc_timer_config_t ledc_timer;
	// ledc_timer.clk_cfg = LEDC_USE_RC_FAST_CLK;
	// ledc_timer.speed_mode = LEDC_LOW_SPEED_MODE,
	// ledc_timer.duty_resolution = LEDC_TIMER_8_BIT;
	// ledc_timer.timer_num = LEDC_TIMER_0,
	// ledc_timer.freq_hz = 2000;

	// ledc_channel_config_t ledc_channel;
	// ledc_channel.gpio_num = M1_SPEED_ENABLE;
	// ledc_channel.speed_mode = LEDC_LOW_SPEED_MODE,
	// ledc_channel.channel = LEDC_CHANNEL_0,
	// ledc_channel.duty = 8;
	// ledc_channel.hpoint = 6;
// https://docs.espressif.com/projects/esp-idf/en/latest/esp32/api-reference/peripherals/ledc.html#_CPPv417ledc_timer_configPK19ledc_timer_config_t
// https://docs.espressif.com/projects/esp-idf/en/latest/esp32/api-reference/peripherals/ledc.html#ledc-api-configure-channel


	// Serial.printf("config ret: %d\n", ledc_timer_config(&ledc_timer));
	// Serial.printf("config ret: %d\n", ledc_channel_config(&ledc_channel));

	ledcAttach(M1_SPEED_ENABLE, freq, resolution);
	ledcAttach(M2_SPEED_ENABLE, freq, resolution);
}

/*
  
*/
void connect_broker()
{
	client.setServer(mqtt_broker, mqtt_port);
  	client.setCallback(callback);

    while (!client.connected()) {
    String client_id = "esp32-client-";
    client_id += String(WiFi.macAddress());
    Serial.printf("The client %s connects to the public MQTT broker\n", client_id.c_str());
    if (client.connect(client_id.c_str(), mqtt_username, mqtt_password)) {
        Serial.println("Public mosquitto.org MQTT broker connected");
    } else {
        Serial.print("failed with state ");
        Serial.print(client.state());
        delay(2000);
    }
  }
}

void connect_wifi()
{
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  int status = WL_IDLE_STATUS;
  Serial.println("\nConnecting");
  while(WiFi.status() != WL_CONNECTED)
  {
    Serial.println(get_wifi_status(status));
    delay(500);
  }
  Serial.println("\nConnected to the WiFi network");
  Serial.print("Local ESP32 IP: ");
  Serial.println(WiFi.localIP());
  Serial.print(" WiFi network (gateway) IP: ");
  Serial.println(WiFi.gatewayIP());
  Serial.print("[+] Subnet Mask : ");
  Serial.println(WiFi.subnetMask());
  Serial.println((String)"[+] RSSI : " + WiFi.RSSI() + " dB");
}

String get_wifi_status(int status){
    switch(status){
        case WL_IDLE_STATUS:
        return "WL_IDLE_STATUS";
        case WL_SCAN_COMPLETED:
        return "WL_SCAN_COMPLETED";
        case WL_NO_SSID_AVAIL:
        return "WL_NO_SSID_AVAIL";
        case WL_CONNECT_FAILED:
        return "WL_CONNECT_FAILED";
        case WL_CONNECTION_LOST:
        return "WL_CONNECTION_LOST";
        case WL_CONNECTED:
        return "WL_CONNECTED";
        case WL_DISCONNECTED:
        return "WL_DISCONNECTED";
    }
}
#include <math.h>
#include <string.h>

float	CrossProduct(const float vector_v[2], const float vector_w[2])
{
	return ((vector_v[0] * vector_w[1]) - (vector_v[1] * vector_w[0]));
}
/**
 * 
 * gets called whenever message is received in a subscribed topic
 * 
 * Sets the pump on or off based on message
*/
void callback(char *topic, byte *payload, unsigned int length)
{
    // Serial.print("Message arrived in topic: ");
    // Serial.println(topic);
    String data = "";

    for (int i = 0; i < length; i++) {
    //   Serial.print((char)payload[i]);
      data += (char)payload[i];
    }
	const char *data_cstr = data.c_str();
    // Serial.println();
    // Serial.println("-----------------------");
    if (String(topic) == String(motor_topic))
    {
      if (data == "true")
      {
        digitalWrite(PING, HIGH);
      }
      else if(data == "false")
        digitalWrite(PING, LOW);
	  init_stack_array(args);
	  t_split_and_fill(args, data_cstr, ' ');
	  runCommand(args);
	  init_stack_array(args);
    }
	else if (String(topic) == String(speed_topic))
	{
		int new_speed = atoi(data_cstr);
		// Serial.printf("factor pre : %f\n", speed_factor);
		// Serial.printf("int new : %f\n", new_speed);
		// Serial.printf("int seting old : %f\n", speed_setting);
		if (new_speed == speed_setting)
			return;

		speed_setting = new_speed;

		speed_factor = ((float)speed_setting / (float)10);
		// Serial.printf("factor post : %f\n", speed_factor);

	}
	else if (String(topic) == String(joy_stick_topic))
	{
		char split_p1[15][200];
		init_stack_array(split_p1);
		t_split_and_fill(split_p1, data_cstr, ':');
		// Serial.println("split args p1----------------");
		// print_args(split_p1);
		// Serial.printf("[13] en [14]: %s & %s----------------\n", split_p1[10], split_p1[11]);
		// char x_str[15][200];
		// char y_syt[15][200];
		// t_split_and_fill(x_str, split_p1[10], ',');

		const char *x_str = ft_strtrim(split_p1[10], ",y\"");
		const char *y_str = ft_strtrim(split_p1[11], "}");

		// t_split_and_fill(x_str, split_p1[11], ',');
		// Serial.printf("trimmed %s & %s----------------\n", x_str, y_str);
		float vec_yx[2];
		vec_yx[0] = atof(x_str);
		vec_yx[1] = atof(y_str);
		const float vec_along_positive_x[2] = {1, 0};
		const float vec_along_negative_x[2] = {-1, 0};
		float factor_motor_l;
		float factor_motor_r;
		// float magnitude = get_magnitude(vec_yx);
		if (vec_yx[0] >= 0 && vec_yx[1] >= 0) // Top right quarter
		{
			factor_motor_r = CrossProduct(vec_along_positive_x, vec_yx);
		 	factor_motor_l = 1;
		}
		else if (vec_yx[0] < 0 && vec_yx[1] >= 0) // Top left quarter
		{
			factor_motor_l = CrossProduct(vec_yx, vec_along_negative_x);
		 	factor_motor_r = 1;
		}
		else
		{	
			factor_motor_l = 0;
			factor_motor_r = 0;
		}
		int		pwn_motor_r = speed_factor * factor_motor_r * (float)255;
		int		pwn_motor_l = speed_factor * factor_motor_l * (float)255;
		init_stack_array(args);
		// Serial.printf("factor: %f\n", speed_factor);

		char *pwn_motor_l_str = ft_itoa(pwn_motor_l);
		char *pwn_motor_r_str = ft_itoa(pwn_motor_r);
		// Serial.printf("pwn l %s & r %s----------------\n", pwn_motor_l_str, pwn_motor_r_str);

		strcpy(args[0], "o");
		strcpy(args[1], pwn_motor_r_str);
		strcpy(args[2], pwn_motor_l_str);
		runCommand(args);
	 	init_stack_array(args);
		free((void *)pwn_motor_l_str);
		free((void *)pwn_motor_r_str);
		free((void *)y_str);
		free((void *)x_str);
	}
}

//{"angle":{"radian":1.1858197067725307,"degree":67.94246446150684},"direction":
//{"x":"right","y":"up","angle":"up"},"distance":100,"vector":
// {"x":0.375537468118232,"y":0.926807212984096}}

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


void init_stack_array(char args[15][200])
{
  	for(int i=0; i<3; i++)
	{
      for (int j = 0; j < 32; j++)
        args[i][j] = '\0';
    }
}


void runCommand(char args[15][200])
{
	char	cmd = args[0][0];
	int		arg1_l = atoi(args[1]);
	int		arg2_l = atoi(args[2]);
  	// Serial.printf("num arg 1:%d 2:%d\n", arg1_l, arg2_l);
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
		// Serial.printf("sending raw PWM");
		setMotorSpeed(M1_SPEED_ENABLE, M1_MOTOR_FORWARD, M1_MOTOR_BACKWARD, arg1_l);
		setMotorSpeed(M2_SPEED_ENABLE, M2_MOTOR_FORWARD, M2_MOTOR_BACKWARD, arg2_l);
		break;
	default:
		Serial.println("Invalid command");
  }
	init_stack_array(args);

}

void parse_message()
{
	char byteRead;
	int j = 0;
	int i = 0;

	while (Serial.available() > 0)
	{
		if (i == 0)
			init_stack_array(args);
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
}

void print_args(char args[15][200])
{
	if (args[0][0] != '\0')
  	{
		Serial.printf("\n_________\n");
		for (int j = 0; j < 15; j++)
		{
			if (args[j][0] != '\0')
			Serial.printf("i=%d: %s\n", j, args[j]);
		}
	}
}

void loop()
{
	client.loop(); 


	parse_message();
	// Serial.printf("___________\ncurrent arg_i :%d \t index :%d \n", g_arg_index, g_index);
	// print_args(args);

	if (args[0][0] != '\0')
		runCommand(args);
  	

}