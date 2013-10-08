RC_Car
======

Here will be the code for the rc car that will ideally follow the user as he walks/jogs.
heartBeat.cpp:        This will require the car to always be in range of the shutoff recieving a heartbeat. If it ever looses the heartbeat the program will imediately shutdown. If the program recieves the kill command it will shutdown. These commands are all run from seperate threads to try and limit overhead.
pwmController.cpp:    Interface the pwm modules into an easy to use manor that interfaces well with the rc car.
servoController.cpp:  Really just a fancy controller for the pwm to understand how the servo works on the rc car.
trackingTest.cpp:     Will do the object tracking/scoring to identify roughly where the target currently is.
Main.cpp:             Handle all the .cpp files and actually do the following.
Second major robotics project to be uploaded to github.
Third independent project.
First Beaglebone Black project.
