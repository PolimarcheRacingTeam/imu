/*
 * imu.h
 *
 *  Created on: Jun 10, 2017
 *      Author: Seb
 */

#ifndef IMU_H_
#define IMU_H_


#include "inv_mpu.h" //libreria Invensense adattata per renesas rx
#include "i2c.h"

typedef struct {
	short rawacc[3];
	short rawgyr[3];
	struct{
		float x,y,z;
	} acc;
	struct{
		float x,y,z;
	} gyr;

	uint16_t acc_sens;
	float gyr_sens;

} imudata;

extern imudata imu;

int imu_init();

//data must be of type float[6]
int imu_read();

//data must be of type int16_t[6]
int imu_read_raw();


#endif /* IMU_H_ */
