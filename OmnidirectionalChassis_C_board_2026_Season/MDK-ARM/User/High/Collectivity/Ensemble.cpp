#include "Ensemble.hpp"
//IMU

Can_RX_T2 Can_RX_imu;
IMU::CH104 ch104;

void IMU::CH104::Dataupdate_accel(uint8_t *data)
{
    imu_acc[0] = (int16_t)(data[0] | data[1] << 8);
    imu_acc[1] = (int16_t)(data[2] | data[3] << 8);
    imu_acc[2] = (int16_t)(data[4] | data[5] << 8);

    accel[0] = (float)imu_acc[0] * 0.001f;
    accel[1] = (float)imu_acc[1] * 0.001f;
    accel[2] = (float)imu_acc[2] * 0.001f;
}

void IMU::CH104::Dataupdate_gyro(uint8_t *data)
{
    imu_gyro[0] = (int16_t)(data[0] | data[1] << 8);
    imu_gyro[1] = (int16_t)(data[2] | data[3] << 8);
    imu_gyro[2] = (int16_t)(data[4] | data[5] << 8);

    gyro[0] = (float)imu_gyro[0] * 0.1f;
    gyro[1] = (float)imu_gyro[1] * 0.1f;
    gyro[2] = (float)imu_gyro[2] * 0.1f;
}

void IMU::CH104::Dataupdate_angle(uint8_t *data)
{
    imu_angle[0] = (int16_t)(data[0] | data[1] << 8);
    imu_angle[1] = (int16_t)(data[2] | data[3] << 8);
    imu_angle[2] = (int16_t)(data[4] | data[5] << 8);

    angle[0] = (float)(imu_angle[0] + 180.0f) * 0.01f;
    angle[1] = (float)(imu_angle[1] + 90.0f ) * 0.01f;
    angle[2] = (float)(imu_angle[2] + 180.0f) * 0.01f;

    Yaw_8192 = angle[2] / 360.0f * 8192.0f;
}

void IMURxData()
{
    switch (Can_RX_imu.rxHeader_imu.StdId)
    {
		case 0x188:
            ch104.Dataupdate_accel(Can_RX_imu.rxdata_imu);
            break;

        case 0x288:
            ch104.Dataupdate_gyro(Can_RX_imu.rxdata_imu);
            break;

        case 0x388:
            ch104.Dataupdate_angle(Can_RX_imu.rxdata_imu);
            break;
    }
}
