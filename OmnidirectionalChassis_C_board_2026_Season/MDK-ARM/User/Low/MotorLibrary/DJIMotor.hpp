#ifndef _DJIMOTOR_HPP_
#define _DJIMOTOR_HPP_

#include <stdint.h>
#include <can.h>

#define MY_PI 3.1415926535897932384626433832795f

extern CAN_TxHeaderTypeDef DJI_txHeader;
extern uint8_t DJI_TX_Data[8];
extern uint32_t txMailbox_DJI;

typedef struct
{
    CAN_RxHeaderTypeDef rxHeader;
    uint8_t rxdata[8];
}Can_RX_T;
extern Can_RX_T Can_RX;

namespace motor
{
    class DJIMotor
    {
    public:
        DJIMotor(uint32_t recv_id) { recv_id_ = recv_id; };
        
        uint32_t recv_id_;              //����id
        float angle_8191;               //ת�ӻ�е�Ƕ�  0-8191
        int16_t speed_rpm;                //ת���ٶ�      rpm
        float torqueCurrent;            //ʵ��Ť�ص���
        uint8_t  temperate;             //����¶�      ���϶�
        float torque;                   //���Ť��

        float angel_360;                //ת�ӻ�е�Ƕ�  0-360
        float speed_m;                  //ת���ٶ�      m/s
        float last_angle_360;           //��һ��ת�ӻ�е�Ƕ�  0-360
        float first_angle_360;          //��һ��ת�ӻ�е�Ƕ�  0-360

        float MotorSet;                 //�������ֵ
        void DataUpdate(uint8_t *data);

    };

    class YawMotor
    {
        public:
            float angle_8191;
            float theta;
            float theta_rad;
            float theta_planning;
    };

    class DJIMotorController
    {
    public:
        DJIMotorController() = default;

        bool SendMotorData(CAN_HandleTypeDef* hcan, uint16_t StdId, int16_t motor1, int16_t motor2, int16_t motor3, int16_t motor4);
        
        bool SendMotorData_0x200(CAN_HandleTypeDef* hcan, int16_t motor1, int16_t motor2, int16_t motor3, int16_t motor4)
        {
            return SendMotorData(hcan, 0x200, motor1, motor2, motor3, motor4);
        }

        bool SendMotorData_0x1FF(CAN_HandleTypeDef* hcan, int16_t motor1, int16_t motor2, int16_t motor3, int16_t motor4)
        {
            return SendMotorData(hcan, 0x1FF, motor1, motor2, motor3, motor4);
        }

        bool SendMotorData_0x1FE(CAN_HandleTypeDef* hcan, int16_t motor1, int16_t motor2, int16_t motor3, int16_t motor4)
        {
            return SendMotorData(hcan, 0x1FE, motor1, motor2, motor3, motor4);
        }

    private:
        bool send_can_message(CAN_HandleTypeDef* hcan, uint16_t id, const uint8_t* data, uint8_t length);
    };
}

void RmMotorRxData(void);
void DJImotorTX_0x200(CAN_HandleTypeDef* hcan);
void DJImotorTX_0x1FF(CAN_HandleTypeDef* hcan);
void DJImotorTX_0x1FE(CAN_HandleTypeDef* hcan);

#endif
