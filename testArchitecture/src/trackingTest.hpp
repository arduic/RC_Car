//============================================================================
// Name        : trackingTest.hpp
// Author      : Patrick
<<<<<<< HEAD
// Version     : 0.2
// Date Created: Sep 24, 2013
// Date Edited : Oct 23, 2013
=======
// Version     : 0.1
// Date Created: Sep 24, 2013
// Date Edited :
>>>>>>> aee562f62db8749c072a066d3d83f6b458f2ce20
// Copyright   : Your copyright notice
// Description : Header file for the respective cpp file. The important parts are the constants. HMIN - VMAX are the thresholds which ideally would be calculated live rather than being constants but for now.
//				 The initals represent a base line for the image position. Currently these are completely wrong and will obviously need to be tweaked.
//				 Lastly are the K values which represent how much we care about X vs area for the scoring algorithm. They are nothing more than scales to eachother.
//============================================================================
<<<<<<< HEAD
//version chages: I believe I made changes to the functions from 0.1 so these prototypes were changed
=======
>>>>>>> aee562f62db8749c072a066d3d83f6b458f2ce20

#ifndef TRACKINGTEST_HPP_
#define TRACKINGTEST_HPP_

<<<<<<< HEAD
#include <cv.h>
using namespace cv;
=======
//#include <cv.h>
//using namespace cv;
>>>>>>> aee562f62db8749c072a066d3d83f6b458f2ce20
/*******************************************************************************
 * 					Constants
 *******************************************************************************/
//Obviously these will need to be played with and if I was super cool I would probably apply this scoring concept to the limits thus evaluating where the threshold should be. Thing is, i'm lazy right now.
#define INITAL_X 64
#define INITAL_AREA 64
<<<<<<< HEAD
#define HMIN 100
#define SMIN 165
#define VMIN 60
#define HMAX 110
#define SMAX 240
#define VMAX 150
=======
#define HMIN 90
#define SMIN 50
#define VMIN 0
#define HMAX 130
#define SMAX 140
#define VMAX 50
>>>>>>> aee562f62db8749c072a066d3d83f6b458f2ce20
#define KX 2
#define KAREA 1

//kp ki kd will not be defined as they are better used with tuning. the inital stuff is used incase target is lost.
//Scoring should also have a scale of sorts but that also needs to be tuned I think.
/*******************************************************************************
 * 					Functions
 *******************************************************************************/
double scoreObject(double x, double area, double previousX, double previousArea, double kx, double kArea);	//This will calculate how likely it is that this object is the target based on movement from previous location

//This will be called for both the X location and the Area, important calculate deltaTime immediately after sensor data. DO NOT DO IT INLINE WITH FUNCTION
double PIDFunction(double preVal, double curVal, double deltaTime, double &integral, double kp, double ki, double kd);	//Calculate the location of the object using PID algorithms

<<<<<<< HEAD
int imageDetection(Mat image, double &x, double &area);
=======
//int imageDetection(Mat image, double &x, double &area);
>>>>>>> aee562f62db8749c072a066d3d83f6b458f2ce20

#endif /* TRACKINGTEST_HPP_ */
