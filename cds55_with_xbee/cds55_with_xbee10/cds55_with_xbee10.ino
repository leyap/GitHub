
#include <Arduino.h>
#include <SPI.h>
//#include <ServoCds55.h>
#include "pins_arduino.h"

#include "split.h"
#include "read_serial.h"

#include "cds55.h"
#include "hexapod.h"
#include "protocol.h"

#define DEVICE 0X07

#define BUF_SIZE 3
char buf[BUF_SIZE];

xbee_protocol_t xbee_data;

float lvalue1;
float lvalue2;
float rvalue1;
float rvalue2;

float step = 0;
uint8_t r = 10;
uint8_t r2 = 30;
uint8_t leg2 = 50;
uint8_t leg3 = 30;

uint8_t lvalue_leg2;
uint8_t rvalue_leg2;


//
void setup () {
	Serial.begin (9600);
	SPI.begin ();
	digitalWrite (SS, LOW);
	//SPI.setClockDivider (SPI_CLOCK_DIV8);
	delay (2000);
	ctrl_all_leg (0, 0, 0);
}

//
void loop () {
	digitalWrite (SS, LOW);

	if (read_serial (buf, sizeof (xbee_protocol_t))) {
		if (xbee_checksum (&xbee_data) == xbee_data.checksum && xbee_data.device == DEVICE) {
			switch (xbee_data.cmd) {
				case '+':
					value += xbee_data.value * step; 
					lvalue1 = r * cos (value);
					lvalue2 = r2 * sin (value);
					rvalue1 = -r * cos (value);
					rvalue2 = -r2 * sin (value);
					first_step (lvalue1, lvalue_leg2, leg3, 1);
					second_step (rvalue1, rvalue_leg2, leg3, 1);
					break;
				case '-':
					value -= xbee_data.value * step; 
					break;
					lvalue1 = r * cos (value);
					lvalue2 = r2 * sin (value);
					rvalue1 = -r * cos (value);
					rvalue2 = -r2 * sin (value);
					first_step (lvalue1, lvalue_leg2, leg3, 1);
					second_step (rvalue1, rvalue_leg2, leg3, 1);
					break;
				case 'l':
					lvalue1 = r * cos (value);
					lvalue2 = r2 * sin (value);
					rvalue1 = -r * cos (value);
					rvalue2 = -r2 * sin (value);
					value += xbee_data.value * step; 
					first_step (lvalue1, lvalue_leg2, leg3, -1);
					second_step (rvalue1, rvalue_leg2, leg3, -1);
					break;
				case 'r':
					lvalue1 = r * cos (value);
					lvalue2 = r2 * sin (value);
					rvalue1 = -r * cos (value);
					rvalue2 = -r2 * sin (value);
					value += xbee_data.value * step; 
					first_step (lvalue1, lvalue_leg2, leg3, -1);
					second_step (rvalue1, rvalue_leg2, leg3, -1);
					break;
				case '1':
					leg2 += 3;
					break;
				case '2':
					leg2 -= 3;
					break;
				case '3':
					leg3 += 3;
					break;
				case '4':
					leg3 -= 3;
					break;
			}
		}
		if (buf[0] =='+') {
			step += 18*3.14/180;
		} else if (buf[0] == '-') {
			step -= 18*3.14/180;
		} 
		lvalue1 = r * cos (step);
		lvalue2 = r2 * sin (step);
		rvalue1 = -r * cos (step);
		rvalue2 = -r2 * sin (step);

		if (lvalue2 > 0) lvalue2 = 0;
		if (rvalue2 > 0) rvalue2 = 0;

		if (buf[0] == 'H') {
			leg2 += 3;
			if (leg2 > 200) leg2 = 200;
		} else if (buf[0] == 'L') {
			leg2 -= 3;
			if (leg2 < 0) leg2 = 0;
		} 
		if (buf[0] == 'h') {
			leg3 += 3;
			if (leg3 > 200) leg3 = 200;
		} else if (buf[0] == 'l') {
			leg3 -= 3;
			if (leg3 < 0) leg3 = 0;
		}

		lvalue_leg2 = lvalue2+leg2;
		rvalue_leg2 = rvalue2+leg2;
		// lvalue_leg2 = constrain (lvalue_leg2, 0, 250);
		// rvalue_leg2 = constrain (rvalue_leg2, 0, 250);
		first_step (lvalue1, lvalue_leg2, leg3);
		second_step (rvalue1, rvalue_leg2, leg3);
		//step += 18* 3.14/180;
		delay (10);
	}
	digitalWrite (SS, HIGH);
}

