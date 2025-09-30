#include "RemoteOperation.hpp"

extern PID::PID_ Revolve_PidInstance;

RemoteOperation::RemoteOperation_ VehicleDirection;
RemoteOperation::Motortarget M3508_201_Remove;
RemoteOperation::Motortarget M3508_202_Remove;
RemoteOperation::Motortarget M3508_203_Remove;
RemoteOperation::Motortarget M3508_204_Remove;

bool dead_zone_flag0 = false;
bool dead_zone_flag1 = false;
bool dead_zone_flag2 = false;
bool dead_zone_flag3 = false;
bool dead_zone_flag4 = false;

void ChassisSolution()
{
    StandardizationOfWeightsAndMeasures_DR16();
    Judgment();
    ModeSelection();
    
    M3508_201_Remove.target = VehicleDirection.vx  - VehicleDirection.vy + VehicleDirection.w;
    M3508_202_Remove.target = -VehicleDirection.vx - VehicleDirection.vy + VehicleDirection.w;
    M3508_203_Remove.target = -VehicleDirection.vx + VehicleDirection.vy + VehicleDirection.w;
    M3508_204_Remove.target = VehicleDirection.vx  + VehicleDirection.vy + VehicleDirection.w;

}

void StandardizationOfWeightsAndMeasures_DR16()
{
    Dead_zone();

    // if(×´Ì¬»ú¼üÊóÄ£Ê½)
    // {
    Key_Mou();
    // }

    if(dead_zone_flag3 == true)
    {
      dr16.vx_left = 0.0f;//vx,vxÊÇ¶ÔÒ£¿ØÆ÷¶øÑÔ
    }
    else
    {
      dr16.vx_left = (dr16.rc.ch3 - 1024.0f)/660.0f;//vx,vxÊÇ¶ÔÒ£¿ØÆ÷¶øÑÔ
    }

    if(dead_zone_flag2 == true)
    {
      dr16.vy_left = 0.0f;
    }
    else
    {
      dr16.vy_left = (dr16.rc.ch2 - 1024.0f)/660.0f;
    }

    if(dead_zone_flag1 == true)
    {
      dr16.vx_right = 0.0f;
    }
    else
    {
      dr16.vx_right = (dr16.rc.ch1 - 1024.0f)/660.0f;
    }

    if(dead_zone_flag0 == true)
    {
      dr16.vy_right = 0.0f;
    }
    else
    {
      dr16.vy_right = (dr16.rc.ch0 - 1024.0f)/660.0f;
    }

    if(dead_zone_flag4 == true)
    {
      dr16.Roller = (dr16.reserved_.reserved - 1024.0f)/660.0f;
    }
    else
    {
      dr16.Roller = (dr16.reserved_.reserved - 1024.0f)/660.0f;
    }      
}

void Dead_zone()
{
    if(dr16.rc.ch0 - 1024.0f < 15.0f && dr16.rc.ch0 - 1024.0f > -15.0f)
    {
      dead_zone_flag0 = true;
    }
    else
    {
      dead_zone_flag0 = false;
    }

    if(dr16.rc.ch1 - 1024.0f < 15.0f && dr16.rc.ch1 - 1024.0f > -15.0f)
    {
      dead_zone_flag1 = true;
    }
    else
    {
      dead_zone_flag1 = false;
    }

    if(dr16.rc.ch2 - 1024.0f < 15.0f && dr16.rc.ch2 - 1024.0f > -15.0f)
    {
      dead_zone_flag2 = true;
    }
    else
    {
      dead_zone_flag2 = false;
    }

    if(dr16.rc.ch3 - 1024.0f < 15.0f && dr16.rc.ch3 - 1024.0f > -15.0f)
    {
      dead_zone_flag3 = true;
    }
    else
    {
      dead_zone_flag3 = false;
    }

    if(dr16.reserved_.reserved - 1024.0f < 15.0f && dr16.reserved_.reserved - 1024.0f > -15.0f)
    {
      dead_zone_flag4 = true;
    }
    else
    {
      dead_zone_flag4 = false;
    }
}

void ModeSelection()
{
    if(dr16.rc.s1 == 3)//µ×ÅÌ²»¸úËæ
    {
      VehicleDirection.w  = 8911.0f*dr16.Roller + 2500.0f*dr16.q + 2500.0f*dr16.e;
      VehicleDirection.vx = 8911.0f*(dr16.vx_left *  cosf(M6020_206.theta_planning + 0.02f*0.005512f*VehicleDirection.w) + dr16.vy_left * sinf(M6020_206.theta_planning + 0.02f*0.005512f*VehicleDirection.w)) + 3000.0f*((dr16.w + dr16.s) *  cosf(M6020_206.theta_planning + 0.02f*0.005512f*VehicleDirection.w) + (dr16.a + dr16.d) * sinf(M6020_206.theta_planning + 0.02f*0.005512f*VehicleDirection.w));
      VehicleDirection.vy = 8911.0f*(dr16.vx_left * -sinf(M6020_206.theta_planning + 0.02f*0.005512f*VehicleDirection.w) + dr16.vy_left * cosf(M6020_206.theta_planning + 0.02f*0.005512f*VehicleDirection.w)) + 3000.0f*((dr16.w + dr16.s) * -sinf(M6020_206.theta_planning + 0.02f*0.005512f*VehicleDirection.w) + (dr16.a + dr16.d) * cosf(M6020_206.theta_planning + 0.02f*0.005512f*VehicleDirection.w));
    }

    if(dr16.rc.s1 == 1)//µ×ÅÌ¸úËæ
    {   
        dr16.transform_flag = 0;
				
		if(dr16.Little_spinning_L_flag == true || dr16.Key_q_flag == true)
        {
            dr16.Little_spinning_R_flag = false;
            VehicleDirection.w  =  /*2500.0f + */2500.0f*dr16.q_;
            VehicleDirection.vx = 8911.0f*(dr16.vx_left *  cosf(M6020_206.theta_planning + 0.02f*13.78f) + dr16.vy_left * sinf(M6020_206.theta_planning + 0.02f*13.78f)) + 3000.0f*((dr16.w + dr16.s) *  cosf(M6020_206.theta_planning + 0.02f*13.78f) + (dr16.a + dr16.d) * sinf(M6020_206.theta_planning + 0.02f*13.78f));
            VehicleDirection.vy = 8911.0f*(dr16.vx_left * -sinf(M6020_206.theta_planning + 0.02f*13.78f) + dr16.vy_left * cosf(M6020_206.theta_planning + 0.02f*13.78f)) + 3000.0f*((dr16.w + dr16.s) * -sinf(M6020_206.theta_planning + 0.02f*13.78f) + (dr16.a + dr16.d) * cosf(M6020_206.theta_planning + 0.02f*13.78f));
        }
				
        else if(dr16.Little_spinning_R_flag == true || dr16.normal == true || dr16.Key_q_flag == false)
        {
            dr16.Little_spinning_L_flag = false;
            VehicleDirection.vx = 8911.0f*dr16.vx_left + 3000*(dr16.w + dr16.s);
            VehicleDirection.vy = 8911.0f*dr16.vy_left + 3000*(dr16.a + dr16.d);
            VehicleDirection.w = Revolve_PidInstance.NormalPID(M6020_206.theta_planning, 0.0f);
        }
    }

    if(dr16.rc.s1 == 2)
    {
        if(dr16.transform_flag == 0)
        {
            dr16.Little_spinning_L_flag = false;
            dr16.Little_spinning_R_flag = false;
        }
        dr16.transform_flag = 1;
    }
}

void Judgment()
{
    if(dr16.Little_spinning_L_flag == false && dr16.Little_spinning_R_flag == false)
    {
        dr16.normal = true;
    }

    if(dr16.rc.s1 == 2 && dr16.rc.s2 == 2)
    {
        if(dr16.rc.ch3 >= 1354)
        {
            dr16.left_above = true;
        }
        else if(dr16.rc.ch3 <= 694)
        {
            dr16.left_under = true;
        }

        else if(dr16.rc.ch2 >= 1354)
        {
            dr16.left_left = true;
        }
        else if(dr16.rc.ch2 <= 694)
        {
            dr16.left_right = true;
        }

        if(dr16.left_above == true && dr16.left_under == true)
        {
            dr16.Clockwise_flag = true;
            dr16.normal = false;
            dr16.left_above = false;
            dr16.left_under = false;
        }

        if(dr16.left_left  == true && dr16.left_right == true)
        {
            dr16.Disclockwise_flag = true;
            dr16.normal = false;
            dr16.left_left  = false;
            dr16.left_right = false;
        }
    }
}

void Key_Mou()
{
    dr16.w =  1.0f * dr16.key.w;
    dr16.a = -1.0f * dr16.key.a;
    dr16.s = -1.0f * dr16.key.s;
    dr16.d =  1.0f * dr16.key.d;
    dr16.q = -1.0f * dr16.key.q;
    dr16.e =  1.0f * dr16.key.e;
    if(dr16.rc.s1 == 1)
    {
      if(dr16.key.q == 1)
      {
        dr16.q_ = 1.0f;
        dr16.Key_q_flag = true;
      }
      if(dr16.key.e == 1)
      {
        dr16.q_ = 0.0f;
        dr16.Key_q_flag = false;
      }
    }
}

