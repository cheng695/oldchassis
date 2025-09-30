#ifndef _USER_CAN_HPP_
#define _USER_CAN_HPP_

#include <can.h>
#include "../MotorLibrary/DJIMotor.hpp"
#include "../User/High/Collectivity/Ensemble.hpp"

#ifdef __cplusplus
extern "C" {
#endif
	
void CAN_ConfigFilter(void);

#ifdef __cplusplus
}
#endif

#endif
