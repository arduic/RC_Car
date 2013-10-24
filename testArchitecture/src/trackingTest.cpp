//============================================================================
// Name        : trackingTest.cpp
// Author      : Patrick
<<<<<<< HEAD
// Version     : 0.2
// Date Created: Sep 24, 2013
// Date Edited : Oct 23, 2013
// Copyright   : Your copyright notice
// Description : Objective of the final cpp file. Find all objects on an image, value which one is the best, and than use PID to predict the actual location of that object assuming it is the previous object.
//============================================================================
//Version changes. Fixed some serious bugs (seg faults and location calculations). Tried to improve efficieny.

#include <cv.h>
#include <highgui.h>
//#include "opencv2/imgproc/imgproc.hpp"
=======
// Version     : 0.1
// Date Created: Sep 24, 2013
// Date Edited :
// Copyright   : Your copyright notice
// Description : Objective of the final cpp file. Find all objects on an image, value which one is the best, and than use PID to predict the actual location of that object assuming it is the previous object.
//============================================================================
/*
#include <cv.h>
#include <highgui.h>
>>>>>>> aee562f62db8749c072a066d3d83f6b458f2ce20
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "trackingTest.hpp"
<<<<<<< HEAD
#include "/usr/local/include/opencv2/opencv.hpp"
=======
>>>>>>> aee562f62db8749c072a066d3d83f6b458f2ce20

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
<<<<<<< HEAD
	//printf("%s\n","1");
=======
>>>>>>> aee562f62db8749c072a066d3d83f6b458f2ce20
	Mat HSV,threshold;
	//Mark every point that is within a certain HSV color range. (RGB sucks thus HSV)
	cvtColor(image,HSV,COLOR_BGR2HSV);
	inRange(HSV,Scalar(HMIN,SMIN,VMIN),Scalar(HMAX,SMAX,VMAX),threshold);
<<<<<<< HEAD
	//printf("%s\n","2");
=======

>>>>>>> aee562f62db8749c072a066d3d83f6b458f2ce20
	//Get rid of floating dots and expand ones that are close together
	Mat erodeElement = getStructuringElement( MORPH_RECT,Size(3,3));
	//dilate with larger element so make sure object is easily linked together
	Mat dilateElement = getStructuringElement( MORPH_RECT,Size(8,8));
<<<<<<< HEAD

	/*erode(threshold,threshold,erodeElement);
	erode(threshold,threshold,erodeElement);
	dilate(threshold,threshold,dilateElement);
	dilate(threshold,threshold,dilateElement);*/

	erode(threshold,threshold,erodeElement,Point(-1,-1),2);
	dilate(threshold,threshold,dilateElement,Point(-1,-1),2);

	//printf("%s\n","3");
=======
	erode(threshold,threshold,erodeElement);
	erode(threshold,threshold,erodeElement);
	dilate(threshold,threshold,dilateElement);
	dilate(threshold,threshold,dilateElement);

>>>>>>> aee562f62db8749c072a066d3d83f6b458f2ce20
	//Find the contours (objects) on this image
	vector< vector<Point> > contours;
	vector<Vec4i> hierarchy;
	findContours(threshold,contours,hierarchy,CV_RETR_CCOMP,CV_CHAIN_APPROX_SIMPLE );
<<<<<<< HEAD
	if(contours.size()==0 && hierarchy.size()==0)
		return -2;
	//printf("%s\n","4");
=======

>>>>>>> aee562f62db8749c072a066d3d83f6b458f2ce20
	//Loop through all of the contours we have found (I may be able to remove the hiearchy that findContours made but I don't know how else to do this for loop yet)
	double score = 9000000;
	double theX,theArea;
	for (int index = 0; index >= 0; index = hierarchy[index][0]) {
		//Find the x position and area of the image
<<<<<<< HEAD
		//printf("%s\n","5");
		//Moments moment = moments((Mat)contours[index]);
		Moments moment = moments((Mat)contours[index],true);
		//Store the evaluation in a temp directory and compare if this score is LOWER (0 means target did not move) if it is update the possible position
		//double tempX = moment.m00;
		//double tempArea = moment.m10/moment.m00;
		//printf("%s\n","6");
		double temp = scoreObject(moment.m10/moment.m00,moment.m00,x,area,KX,KAREA);
		//double temp = scoreObject(tempX,tempArea,x,area,KX,KAREA);
		//cout << tempX << " " << tempArea << " " << temp << endl;
		if(temp < score){
			theX = moment.m10/moment.m00;
			theArea = moment.m00;
			score = temp;
		}
		//printf("%s\n","7");

	}
	//printf("%s\n","8");
	//printf("x location: %f, area: %f",theX,theArea);
=======
		Moments moment = moments((cv::Mat)contours[index]);
		//Store the evaluation in a temp directory and compare if this score is LOWER (0 means target did not move) if it is update the possible position
		double temp = scoreObject(moment.m00,moment.m10/moment.m00,x,area,KX,KAREA);
		if(temp < score){
			theX = moment.m00;
			theArea = moment.m10/moment.m00;
			score = temp;
		}
	}
>>>>>>> aee562f62db8749c072a066d3d83f6b458f2ce20
	//If we found at least 1 target update the previous locations to be the new ones and return 0 (no error)
	if (score != 9000000){
		x = theX;
		area = theArea;
		return 0;
	}else{	//If we found no valid targets than we return -1 and probably shut down
		return -1;
	}
}
<<<<<<< HEAD
=======
*/
>>>>>>> aee562f62db8749c072a066d3d83f6b458f2ce20
