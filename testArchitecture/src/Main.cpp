<<<<<<< HEAD
//============================================================================
// Name        : Main.cpp
// Author      : Patrick
// Version     : 0.2
// Date Created: Sep 24, 2013
// Date Edited : Oct 23, 2013
// Copyright   : Your copyright notice
// Description : Main loop to follow a person
//				 This needs to first run a setup, than find object, evaluate best one, estimate where it is.
//				 Estimate how much to turn and accelerate.
//				 Listen to the heart on seperate pthreads.
//============================================================================
//Version changes: 	I created a way to measure fps of the camera with image tracking.
//					It will likely also be used for the final main file.
#include <time.h>
=======
>>>>>>> aee562f62db8749c072a066d3d83f6b458f2ce20
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
<<<<<<< HEAD
#include <cv.h>
#include <highgui.h>
#include "trackingTest.hpp"
#include "/usr/local/include/opencv2/opencv.hpp"
=======
//#include <cv.h>
//#include <highgui.h>
>>>>>>> aee562f62db8749c072a066d3d83f6b458f2ce20

//List of things to implement in order
//heartBeat, PWM, Servo, tracking, main

//So what main will do.
//in a while(1)
//find objects, evaluate for best object, if no valid objects stap!, else use PID to estimate where it is.
//Evaluate where the object is to turn the car.
//Evaluate how far the object is to control speed of the car.
//With the interrupts for heartBeat shutdown the car if we ever lose long range coms, also if we see the stop radio command STOP
using namespace std;
<<<<<<< HEAD
using namespace cv;

int main() {

	/*VideoCapture cameraImage(0);
	cameraImage.set(CV_CAP_PROP_FRAME_WIDTH,1920);
	cameraImage.set(CV_CAP_PROP_FRAME_HEIGHT,1080);
    if(!cameraImage.isOpened()){
    	printf("%s\n","Failed to connect to the camera.");
    	return -1;
    }
    printf("%s\n","Alright let's get it started in here");
	Mat image;
	cameraImage >> image;
	if(image.empty()){
		printf("%s\n","No image");
		return -2;
	}
	imwrite("test.png",image);*/


	double x = 1043;
	double area = 28789;
	struct timespec start,end;
	int trials = 1000;
	VideoCapture cameraImage(0);
	cameraImage.set(CV_CAP_PROP_FRAME_WIDTH,1280);
	cameraImage.set(CV_CAP_PROP_FRAME_HEIGHT,720);
    if(!cameraImage.isOpened()){
    	printf("%s\n","Failed to connect to the camera.");
    	return -1;
    }
    cout << cameraImage.get(CV_CAP_PROP_FOURCC) << endl;
    cout << cameraImage.get(CV_CAP_PROP_FORMAT) << endl;
    cout << cameraImage.get(CV_CAP_PROP_MODE) << endl;
    printf("%s\n","Alright let's get it started in here");
    //system("v4l2-ctl --set-fmt-video=pixelformat=1");		Doesn't work. Camera is being used by program so terminal cannot excute this code to modify setup
	Mat image;

	clock_gettime(0, &start);	//ECLIPSE!!! apparently, even though CLOCK_REALTIME will build and run I tested this. Eclipse still thinks it's an error and will flag it. Thus use the value of CLOCK_REALTIME to shut it up
	for(int i=0; i<trials; i++){
		cameraImage >> image;
		imageDetection(image,x,area);
	}

	clock_gettime(0,&end);
	double difference = (end.tv_sec - start.tv_sec) + (double)(end.tv_nsec - start.tv_nsec)/1000000000.0;
	double fps = (1.0/difference)*trials;
	cout << "It took " << difference << " seconds to process " << trials << " frames" << endl;
	cout << "my fps is: " << fps << endl;



	/*if(setupPWM()){
=======

int main() {
	if(setupPWM()){
>>>>>>> aee562f62db8749c072a066d3d83f6b458f2ce20
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
<<<<<<< HEAD
	return 0;*/
=======
	return 0;
>>>>>>> aee562f62db8749c072a066d3d83f6b458f2ce20


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
<<<<<<< HEAD


	//while(1){}
=======
	while(1){}
>>>>>>> aee562f62db8749c072a066d3d83f6b458f2ce20

}
