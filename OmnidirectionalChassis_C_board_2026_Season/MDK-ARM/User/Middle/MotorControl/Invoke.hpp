#ifndef _INVOKE_HPP_
#define _INVOKE_HPP_ 

#include "PID.hpp"
#include "../User/Low/UniversalAsynchronousTransceiver/Clicker.hpp"
#include "../User/Low/MotorLibrary/DJIMotor.hpp"

extern motor::DJIMotor M3508_201;
extern motor::DJIMotor M3508_202;
extern motor::DJIMotor M3508_203;
extern motor::DJIMotor M3508_204;
extern motor::DJIMotor M2006_205;

extern RemoteOperation::Motortarget M3508_201_Remove;
extern RemoteOperation::Motortarget M3508_202_Remove;
extern RemoteOperation::Motortarget M3508_203_Remove;
extern RemoteOperation::Motortarget M3508_204_Remove;
extern RemoteOperation::Motortarget M2006_205_Remove;

extern PID::PID_ M3508_202_PidInstance;
extern PID::PID_ M3508_201_PidInstance;
extern PID::PID_ M3508_203_PidInstance;
extern PID::PID_ M3508_204_PidInstance;
extern PID::PID_ M2006_205_PidInstance;

extern float tick_last;
extern float tick_now;

void Invoke(void);

#endif
