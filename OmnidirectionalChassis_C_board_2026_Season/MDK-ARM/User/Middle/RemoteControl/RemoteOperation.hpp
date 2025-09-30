#ifndef _REMOTEOPERATION_HPP_
#define _REMOTEOPERATION_HPP_ 

#include "../User/Low/UniversalAsynchronousTransceiver/Clicker.hpp"
#include "../User/Middle/MotorControl/PID.hpp"
#include "../User/Low/MotorLibrary/DJIMotor.hpp"
#include "math.h"

#define Positive_Initial_Angle 6835.0f

namespace RemoteOperation
{
    class RemoteOperation_
    {
        public:
            float vx;
            float vy;
            float w;
    };

    class Motortarget
    {
        public:
            float target;
    };
}

extern Clicker::DR16 dr16;
extern motor::YawMotor M6020_206;

void StandardizationOfWeightsAndMeasures_DR16();
void ChassisSolution();
void ModeSelection();
void Dead_zone();
void Judgment();
void Key_Mou();

#endif
