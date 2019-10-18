#include "pid.h"


/**************************************************************************
函数功能：增量PI控制器
入口参数：编码器测量值，目标速度
返回  值：电机PWM
根据增量式离散PID公式
pwm+=Kp[e（k）-e(k-1)]+Ki*e(k)+Kd[e(k)-2e(k-1)+e(k-2)]
e(k)代表本次偏差
e(k-1)代表上一次的偏差  以此类推
pwm代表增量输出
在我们的速度控制闭环系统里面，只使用PI控制
pwm+=Kp[e（k）-e(k-1)]+Ki*e(k)
**************************************************************************/
int Incremental_PI (int Encoder,int Target)
{        
		float Kp=1.34,Ki=0;       
		static int Bias,Pwm,Last_bias;
		Bias=Encoder-Target;                //计算偏差
		Pwm+=Kp*(Bias-Last_bias)+Ki*Bias;   //增量式PI控制器
		Last_bias=Bias;                           //保存上一次偏差
		return Pwm;                         //增量输出
}
