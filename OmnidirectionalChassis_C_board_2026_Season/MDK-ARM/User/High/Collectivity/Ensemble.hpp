#ifndef _ENSEMBLE_HPP_
#define _ENSEMBLE_HPP_

#include "can.h"

typedef struct
{
    CAN_RxHeaderTypeDef rxHeader_imu;
    uint8_t rxdata_imu[6];
}Can_RX_T2;
extern Can_RX_T2 Can_RX_imu;

namespace IMU
{
    class CH104
    {
    public:
        float gyro[3];
        float accel[3];
		float angle[3];

        int16_t imu_acc[3];     //0X 1Y 2Z
        int16_t imu_gyro[3];    //0pitch 1roll 2yaw
        int16_t imu_angle[3];   //0roll 1pitch 2yaw y x z

        float Yaw_8192;

        void Dataupdate_angle(uint8_t *data);	
        void Dataupdate_accel(uint8_t *data);
        void Dataupdate_gyro(uint8_t *data);
    };
}

void IMURxData();

#endif 
