/*
 * imu.c
 *
 *  Created on: 26 mar 2018
 *      Author: Francesco Conforte
 */



#include "i2c.h"
#include "inv_mpu.h"
#include "imu.h"


imudata imu;

int imu_read(){
	imu_read_raw();

	imu.acc.x=(float)imu.rawacc[0]/imu.acc_sens;
	imu.gyr.x=(float)imu.rawgyr[0]/imu.gyr_sens*0.01745329252;
	imu.acc.y=(float)imu.rawacc[1]/imu.acc_sens;
	imu.gyr.y=(float)imu.rawgyr[1]/imu.gyr_sens*0.01745329252;
	imu.acc.z=(float)imu.rawacc[2]/imu.acc_sens;
	imu.gyr.z=(float)imu.rawgyr[2]/imu.gyr_sens*0.01745329252;

	return 0;
}

int imu_read_raw(){

	mpu_get_accel_reg(imu.rawacc, NULL);
	mpu_get_gyro_reg(imu.rawgyr, NULL);

	return 0;
}


int imu_init(){
	if (mpu_init(0))
		return 0x2;
	if (mpu_set_sensors(INV_XYZ_ACCEL | INV_XYZ_GYRO))
		return 0x3;
	if (mpu_set_sample_rate(1000)) //Hz
		return 0x4;
	mpu_get_accel_sens(&imu.acc_sens);
	mpu_get_gyro_sens(&imu.gyr_sens);
	return 0x0;
}
