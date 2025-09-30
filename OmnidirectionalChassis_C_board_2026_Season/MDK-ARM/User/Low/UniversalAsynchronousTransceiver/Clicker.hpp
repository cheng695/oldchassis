#ifndef _CLICKER_HPP_
#define _CLICKER_HPP_ 

#include <usart.h>
#include <dma.h>

extern uint8_t pData[18];

namespace Clicker{

    class DR16
    {
        public:

            struct 
            { 
                uint16_t ch1; //ÓÒ±ßx
                uint16_t ch0; //ÓÒ±ßy
                uint16_t ch3; //×ó±ßx  ¶«±±Ìì
                uint16_t ch2; //×ó±ßy
                uint8_t s1;
                uint8_t s2;
            }rc;
            struct 
            {
                int16_t x;
                int16_t y;
                int16_t z;
                uint8_t press_l;
                uint8_t press_r;
            }mouse;
            struct 
            {
                char w;
                char s;
                char a;
                char d;
                char q;
                char e;
                char shift;
                char ctrl;
            }key;
            struct
            {
                uint16_t reserved;
            }reserved_;
            

            float vx_left;
            float vy_left;
            float vx_right; 
            float vy_right;
            float Roller;
            
            float w;
            float a;
            float s;
            float d;
            float q;
            float e;

            float q_ = 0.0f;

            bool Key_q_flag = false;
            bool Key_e_flag = false;


            bool Little_spinning_L_flag = false;
            bool Little_spinning_R_flag = false;
            bool Clockwise_flag = false;
            bool Disclockwise_flag = false;
            
            bool left_above = false;
            bool left_under = false;
            bool left_left  = false;
            bool left_right = false;

            bool normal = true;
            int transform_flag = 0;

        void DR16DataUpdata(uint8_t *pData);
    };
}


#endif
