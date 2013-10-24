<<<<<<< HEAD
//============================================================================
// Name        : heartBeat.cpp
// Author      : Patrick
// Version     : 0.2
// Date Created: Sep 24, 2013
// Date Edited :
// Copyright   : Your copyright notice
// Description : This controls the heart of the RC car to comunicate with the wireless controller. It can both kill the car from a signal and a lack of a signal.
//============================================================================
//Note I forgot to put this ^^^ in the first code post but I didn't change anything other than this.

=======
>>>>>>> aee562f62db8749c072a066d3d83f6b458f2ce20
#include "heartBeat.hpp"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <iostream>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <poll.h>

using namespace std;

/*void setupHeart(){	//Setup the heartbeat for future use.
	signal(SIGALRM,emergencyShutDown);
}
void resetTime(){	//Reset the count since last heartbeat
	alarm(3);
}*/
void emergencyShutDown(int x){	//Carefully! shutdown the car, maybe allow reset but probably will require hardware reset
	cout << "Ah I died" << endl;
}

void* loopHeart(void* arg){
	//Setup the heart and setup the gpio var
	unsigned int *gpio = (unsigned int *)arg;
	/*setupHeart();
	resetTime();*/
	//setup memory for poll command
	struct pollfd fdset[2];
	memset((void*)fdset, 0, sizeof(fdset));
	int fd, rc, len;
	char buf[MAX_BUF];
	//configure the gpio for interrupt
	setupGPIOInterrupt(gpio);

	//Open the file and prepare for polling
	snprintf(buf, sizeof(buf), SYSFS_GPIO_DIR "/gpio%d/value", gpio);
	fd = open(buf, O_RDONLY | O_NONBLOCK );
	if (fd < 0) {
		perror("gpio/fd_open");
	}
	//resetTime();
	while(1){
		memset((void*)fdset, 0, sizeof(fdset));
		fdset[0].fd = STDIN_FILENO;
		fdset[0].events = POLLIN;
		fdset[1].fd = fd;
		fdset[1].events = POLLPRI;

		rc = poll(fdset, 2,3000);
		//printf("%d\n",rc);
		// < 0 is an error. 0 means timeout (3000 = 3s) and >0 means poll happened
		if (rc < 0) {
			printf("\npoll() failed!\n");
			return NULL;
		}else if(rc == 0){
			emergencyShutDown(0);
		}else if (fdset[1].revents & POLLPRI) {
			read(fd,buf,MAX_BUF);
			cout << "Beat" << endl;
		}
	}
	return NULL;
}

void* loopKiller(void* arg){
	unsigned int *gpio = (unsigned int*)arg;
	struct pollfd fdset[1];
	memset((void*)fdset, 0, sizeof(fdset));
	int fd, rc;
	char buf[MAX_BUF];
	setupGPIOInterrupt(gpio);
	snprintf(buf, sizeof(buf), SYSFS_GPIO_DIR "/gpio%d/value", gpio);

	fd = open(buf, O_RDONLY | O_NONBLOCK );
	if (fd < 0) {
		perror("gpio/fd_open");
	}
	while(1){
		fdset[0].fd = fd;
		fdset[0].events = POLLPRI;

		rc = poll(fdset, 1,-1);
		if (rc < 0) {
			printf("\npoll() failed!\n");
			return NULL;
		}else{
			emergencyShutDown(1);
		}
	}
	return NULL;
}

int setupGPIOInterrupt(unsigned int* gpio){
	printf("\n%d",gpio);
	int fd, len;
	char buf[MAX_BUF];

	fd = open(SYSFS_GPIO_DIR "/export", O_WRONLY);
	if (fd < 0) {
		perror("gpio/export");
		return -1;
	}
	len = snprintf(buf, sizeof(buf), "%d", gpio);
	write(fd, buf, len);
	close(fd);
	snprintf(buf, sizeof(buf), SYSFS_GPIO_DIR "/gpio%d/direction", gpio);
	fd = open(buf, O_WRONLY);
	if (fd < 0) {
		perror("gpio/export");
		return -1;
	}
	write(fd, "in", 3);
	close(fd);
	snprintf(buf, sizeof(buf), SYSFS_GPIO_DIR "/gpio%d/edge", gpio);
	fd = open(buf, O_WRONLY);
	if (fd < 0) {
		perror("gpio/export");
		return -1;
	}
	write(fd,"rising",7);
	close(fd);

	return 0;
}
