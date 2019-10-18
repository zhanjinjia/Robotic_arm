#include "pid.h"


/**************************************************************************
�������ܣ�����PI������
��ڲ���������������ֵ��Ŀ���ٶ�
����  ֵ�����PWM
��������ʽ��ɢPID��ʽ
pwm+=Kp[e��k��-e(k-1)]+Ki*e(k)+Kd[e(k)-2e(k-1)+e(k-2)]
e(k)������ƫ��
e(k-1)������һ�ε�ƫ��  �Դ�����
pwm�����������
�����ǵ��ٶȿ��Ʊջ�ϵͳ���棬ֻʹ��PI����
pwm+=Kp[e��k��-e(k-1)]+Ki*e(k)
**************************************************************************/
int Incremental_PI (int Encoder,int Target)
{        
		float Kp=1.34,Ki=0;       
		static int Bias,Pwm,Last_bias;
		Bias=Encoder-Target;                //����ƫ��
		Pwm+=Kp*(Bias-Last_bias)+Ki*Bias;   //����ʽPI������
		Last_bias=Bias;                           //������һ��ƫ��
		return Pwm;                         //�������
}
