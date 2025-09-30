#ifndef _BOARDCOMMUNICATION_CtoA_HPP_
#define _BOARDCOMMUNICATION_CtoA_HPP_ 

#include "string.h"
#include "math.h"
#include "../User/Low/UniversalAsynchronousTransceiver/Clicker.hpp"
#include "../User/Low/MotorLibrary/DJIMotor.hpp"
#include "../User/Middle/RemoteControl/RemoteOperation.hpp"
#include "../User/Middle/MotorControl/Invoke.hpp"
#include "../User/High/Collectivity/Ensemble.hpp"

extern motor::YawMotor M6020_206;
extern IMU::CH104 ch104;
extern RemoteOperation::RemoteOperation_ VehicleDirection;
extern int tick_e;

#ifdef __cplusplus
extern "C" {
#endif
	
void Communication_CtoA_Receive();
void Communication_CtoA_Tansmit();

#ifdef __cplusplus
}
#endif

void vofa_send(float x1, float x2, float x3, float x4, float x5, float x6);

#endif

//����ң������֡ͷ���ĸ����״̬����Ҫ��ƣ�
//�գ�yaw��Ƕȣ�֡ͷ������5�����״̬��������״̬����Ҫ��ƣ�