#ifndef _SERIALCALLBACK_HPP_
#define _SERIALCALLBACK_HPP_ 

#include "../User/Low/UniversalAsynchronousTransceiver/Clicker.hpp"
#include "../User/Middle/Communication/BoardCommunication_CtoA.hpp"
#include "../User/Low/MotorLibrary/DJIMotor.hpp"
#include "../User/Middle/RemoteControl/RemoteOperation.hpp"

extern motor::DJIMotor M3508_201;
extern motor::DJIMotor M3508_202;
extern motor::DJIMotor M3508_203;
extern motor::DJIMotor M3508_204;
extern motor::YawMotor M6020_206;
extern motor::DJIMotorController DjimotorController;

extern RemoteOperation::RemoteOperation_ VehicleDirection;
extern RemoteOperation::Motortarget M3508_201_Remove;
extern RemoteOperation::Motortarget M3508_202_Remove;
extern RemoteOperation::Motortarget M3508_203_Remove;
extern RemoteOperation::Motortarget M3508_204_Remove;

#ifdef __cplusplus
extern "C" {
#endif
	
void RxEventCallback(void);

#ifdef __cplusplus
}
#endif



#endif
