#include "chassis_task.h"

#include "robot.h"
#include "remote.h"
#include "dm_motor.h"

extern Robot_State_t g_robot_state;
extern Remote_t g_remote;

float chassis_rad;

DM_Motor_Handle_t* motor;

void Chassis_Task_Init()
{
    // Init chassis hardware

    DM_Motor_Config_t config = {
        .can_bus=1,
        .rx_id=0x15;
        .tx_id=0x05;
        .disable_behavior=DM_MOTOR_HARDWARE_DISABLE,
        .kp=1,
        .kd=1
    };

    motor = DM_Motor_Init(&config);
}

void Chassis_Ctrl_Loop()
{
    // Control loop for the chassis
    DM_Motor_Enable_Motor(motor);
    DM_Motor_Ctrl_MIT(motor, 0, 0, 0);
}

void Chassis_Disable() {
    DM_Motor_Disable_Motor(motor);
}