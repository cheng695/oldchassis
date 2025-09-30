#include "Invoke.hpp"

int tick_e;

void Invoke()
{
    tick_e = tick_now - tick_last;

    if(dr16.rc.s1 == 2 || tick_e >= 200)
    {
        M3508_201.MotorSet = 0.0f;
        M3508_202.MotorSet = 0.0f;
        M3508_203.MotorSet = 0.0f;
        M3508_204.MotorSet = 0.0f;
        // M2006_205.MotorSet = 0.0f;
    }

    else if(dr16.rc.s1 != 2)
    {
        M3508_201.MotorSet = M3508_201_PidInstance.NormalPID((float)M3508_201.speed_rpm, M3508_201_Remove.target);
        M3508_202.MotorSet = M3508_202_PidInstance.NormalPID((float)M3508_202.speed_rpm, M3508_202_Remove.target);
        M3508_203.MotorSet = M3508_203_PidInstance.NormalPID((float)M3508_203.speed_rpm, M3508_203_Remove.target);
        M3508_204.MotorSet = M3508_204_PidInstance.NormalPID((float)M3508_204.speed_rpm, M3508_204_Remove.target);
        // M2006_205.MotorSet = M2006_205_PidInstance.NormalPID((float)M2006_205.speed_rpm, M2006_205_Remove.target);
    }

    DJImotorTX_0x200(&hcan1);
    // DJImotorTX_0x1FF(&hcan1);
}
