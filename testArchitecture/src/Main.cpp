#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <iostream>
#include "pwmController.hpp"
#include "servoController.hpp"
#include "heartBeat.hpp"
#include <pthread.h>
#include <errno.h>
#include <ctype.h>
//#include <cv.h>
//#include <highgui.h>

//List of things to implement in order
//heartBeat, PWM, Servo, tracking, main

//So what main will do.
//in a while(1)
//find objects, evaluate for best object, if no valid objects stap!, else use PID to estimate where it is.
//Evaluate where the object is to turn the car.
//Evaluate how far the object is to control speed of the car.
//With the interrupts for heartBeat shutdown the car if we ever lose long range coms, also if we see the stop radio command STOP
using namespace std;

int main() {
	if(setupPWM()){
		return -1;
	}
	cout << "help1" << endl;
	if(exportPWM(13)){
		return -1;
	}
	cout << "help2" << endl;
	sleep(1);		//this is in seconds no milliseconds. Windows it's mill linux uses this and usleep
	if(setFrequency(50,13,14)){
		return -1;
	}
	cout << "help3" << endl;
	if(setDutyCycle(127,13,14)){
		return -1;
	}
	cout << "help4" << endl;
	cin.ignore();
	if(startStop(1,13,14)){
		return -1;
	}
	cout << "help5" << endl;
	return 0;


	//Alright we are going to create 2 threads but we still need to set priority using the schedule setting for pthread later on.
	/*pthread_t heart, killer;
	if(pthread_create( &heart, NULL,loopHeart,(void*) 15)!=0){
		printf("AHH FAILURE");
		return -1;
	}
	if(pthread_create( &killer, NULL,loopKiller,(void*) 3)!=0){
		printf("CANTASTROPHE");
		return -1;
	}*/
	while(1){}

}
