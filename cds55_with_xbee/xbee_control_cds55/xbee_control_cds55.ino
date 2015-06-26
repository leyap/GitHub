#include <Arduino.h>
#include "keycheck.h"

#define up	8
#define down	A1
#define left	9
#define right	12	

int dtime = 30;

int a_value=0;
int b_value=0;

char buf[12];

//
void setup () {
	//pinMode (A0, INPUT);
	pinMode (A2, INPUT);
	//pinMode (A3, INPUT);

	pinMode (up, INPUT);
	pinMode (down, INPUT);
	pinMode (left, INPUT);
	pinMode (right, INPUT);
	Serial.begin (9600);
	key_delay_time = 1;
}

//
void loop () {

	//a_value = analogRead (A3);
	b_value = analogRead (A2);

	if (b_value < 490)
		Serial.print('+');
	else if (b_value > 530)
		Serial.print('-');
	else if (ispressed (up, 0))
		Serial.print('H');
	else if (ispressed (down, 0))
		Serial.print('L');
	else if (ispressed (left, 0))
		Serial.print('h');
	else if (ispressed (right, 0))
		Serial.print('l');
	delay (dtime);
}


