//============================================================================
// Name        : trackingTest.cpp
// Author      : Patrick
// Version     : 0.1
// Date Created: Sep 24, 2013
// Date Edited :
// Copyright   : Your copyright notice
// Description : Objective of the final cpp file. Find all objects on an image, value which one is the best, and than use PID to predict the actual location of that object assuming it is the previous object.
//============================================================================
/*
#include <cv.h>
#include <highgui.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "trackingTest.hpp"

using namespace std;
using namespace cv;
//So this score method returns 0 is perfect match higher the number the worse the object is. kx and karea are passed because eventually they might be dynamically calculated
double scoreObject(double x, double area, double previousX, double previousArea, double kx, double kArea){
	return abs(x-previousX)*kx+abs(area-previousArea)*kArea;
}
//This is just a general PID function nothing special except that integral is pass by reference
double PIDFunction(double preVal, double curVal, double deltaTime, double &integral, double kp, double ki, double kd){
	double proportion = (curVal-preVal)*kp;
	integral += curVal*deltaTime;
	double derivative = (curVal-preVal)/deltaTime*kd;
	return proportion+integral*ki+derivative;
}
//Find the image, it returns a 0 on sucsses and returns the x and area by reference, this will return the best scored image.
int imageDetection(Mat image, double &x, double &area){
	Mat HSV,threshold;
	//Mark every point that is within a certain HSV color range. (RGB sucks thus HSV)
	cvtColor(image,HSV,COLOR_BGR2HSV);
	inRange(HSV,Scalar(HMIN,SMIN,VMIN),Scalar(HMAX,SMAX,VMAX),threshold);

	//Get rid of floating dots and expand ones that are close together
	Mat erodeElement = getStructuringElement( MORPH_RECT,Size(3,3));
	//dilate with larger element so make sure object is easily linked together
	Mat dilateElement = getStructuringElement( MORPH_RECT,Size(8,8));
	erode(threshold,threshold,erodeElement);
	erode(threshold,threshold,erodeElement);
	dilate(threshold,threshold,dilateElement);
	dilate(threshold,threshold,dilateElement);

	//Find the contours (objects) on this image
	vector< vector<Point> > contours;
	vector<Vec4i> hierarchy;
	findContours(threshold,contours,hierarchy,CV_RETR_CCOMP,CV_CHAIN_APPROX_SIMPLE );

	//Loop through all of the contours we have found (I may be able to remove the hiearchy that findContours made but I don't know how else to do this for loop yet)
	double score = 9000000;
	double theX,theArea;
	for (int index = 0; index >= 0; index = hierarchy[index][0]) {
		//Find the x position and area of the image
		Moments moment = moments((cv::Mat)contours[index]);
		//Store the evaluation in a temp directory and compare if this score is LOWER (0 means target did not move) if it is update the possible position
		double temp = scoreObject(moment.m00,moment.m10/moment.m00,x,area,KX,KAREA);
		if(temp < score){
			theX = moment.m00;
			theArea = moment.m10/moment.m00;
			score = temp;
		}
	}
	//If we found at least 1 target update the previous locations to be the new ones and return 0 (no error)
	if (score != 9000000){
		x = theX;
		area = theArea;
		return 0;
	}else{	//If we found no valid targets than we return -1 and probably shut down
		return -1;
	}
}
*/
