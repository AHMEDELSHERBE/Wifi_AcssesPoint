/*
 * Wifi_Accses.h
 *
 * Created: 03/10/2023 10:56:06
 *  Author: Sherbeny
 */ 


#ifndef WIFI_ACCSES_H_
#define WIFI_ACCSES_H_
#include "../lib/std_types.h"
#define SREG    _SFR_IO8(0x3F)

#define DEFAULT_BUFFER_SIZE		160
#define DEFAULT_TIMEOUT			10000

/* Connection Mode */
#define SINGLE				0
#define MULTIPLE			1

/* Application Mode */
#define NORMAL				0
#define TRANSPERANT			1

/* Application Mode */
#define STATION				1
#define ACCESSPOINT			2
#define BOTH_STATION_AND_ACCESPOINT	3

/* Select Demo */
//#define SEND_DEMO			/* Define SEND demo */

/* Define Required fields shown below */
#define PORT				"80"
#define SSID				"ssid"			//UserName
#define PASSWORD			"password"		//Password

enum ESP8266_RESPONSE_STATUS{
	ESP8266_RESPONSE_WAITING,
	ESP8266_RESPONSE_FINISHED,
	ESP8266_RESPONSE_TIMEOUT,
	ESP8266_RESPONSE_BUFFER_FULL,
	ESP8266_RESPONSE_STARTING,
	ESP8266_RESPONSE_ERROR
};

enum ESP8266_CONNECT_STATUS {
	ESP8266_CONNECTED_TO_AP,
	ESP8266_CREATED_TRANSMISSION,
	ESP8266_TRANSMISSION_DISCONNECTED,
	ESP8266_NOT_CONNECTED_TO_AP,
	ESP8266_CONNECT_UNKNOWN_ERROR
};

enum ESP8266_JOINAP_STATUS {
	ESP8266_WIFI_CONNECTED,
	ESP8266_CONNECTION_TIMEOUT,
	ESP8266_WRONG_PASSWORD,
	ESP8266_NOT_FOUND_TARGET_AP,
	ESP8266_CONNECTION_FAILED,
	ESP8266_JOIN_UNKNOWN_ERROR
};

int8_t Response_Status;
volatile int16_t Counter = 0, pointer = 0;
uint32_t TimeOut = 0;
u8 RESPONSE_BUFFER[DEFAULT_BUFFER_SIZE];

//Functions
void Read_Response(u8* _Expected_Response);
void ESP8266_Clear();
void Start_Read_Response(u8* _ExpectedResponse);
void GetResponseBody(u8* Response, u16 ResponseLength);
bool WaitForExpectedResponse(u8* ExpectedResponse);
bool SendATandExpectResponse(u8* ATCommand, u8* ExpectedResponse);
bool ESP8266_ApplicationMode(u8 Mode);
bool ESP8266_ConnectionMode(u8 Mode);
bool ESP8266_Begin();
bool ESP8266_Close();
bool ESP8266_WIFIMode(u8 _mode);
u8 ESP8266_JoinAccessPoint(u8* _SSID, u8* _PASSWORD);
u8 ESP8266_connected();
u8 ESP8266_Start(u8 _ConnectionNumber, u8* Domain, u8* Port);
u8 ESP8266_Send(u8* Data);
u16 ESP8266_DataAvailable();
u8 ESP8266_DataRead();
u16 Read_Data(u8* _buffer);
ISR (USART_RXC_vect);
#endif /* WIFI_ACCSES_H_ */