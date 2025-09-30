#include "TaskProcess.hpp"
#include <cmsis_os.h>

#ifdef __cplusplus
extern "C" {
#endif

	
void MotorControl(void const * argument)
{
    while(1)
    {
        Invoke();
        osDelay(1);   
    }
}

void RemoteControl(void const * argument)
{
    while(1)
    {
        tick_now++;
        ChassisSolution();
        osDelay(1);   
    }
}

void BoardCommunication(void const * argument)
{
    while(1)
    {
        Communication_CtoA_Tansmit();
		vofa_send(M3508_201.speed_rpm, M3508_202.speed_rpm, M6020_206.theta_planning, 0.0f, M3508_201_Remove.target, M3508_202_Remove.target);
        osDelay(1);   
    }
}

void Buzzer(void const * argument)
{
    while (1)
    {
        if(dr16.Clockwise_flag == true)
        {
            B_star();
            dr16.Little_spinning_L_flag = true;
            dr16.Clockwise_flag = false;
        }
        else if(dr16.Disclockwise_flag == true)
        {
            B_stop();
            dr16.Little_spinning_R_flag = true;
            dr16.Disclockwise_flag = false;
        }
        osDelay(200);
    }   
}

#ifdef __cplusplus
}
#endif
