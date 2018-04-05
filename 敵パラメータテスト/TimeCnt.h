#pragma once
#include "MyPG.h"

//----------------------------------------------
//�t���[�����Ԃ��v���N���X
//----------------------------------------------
class FrameMeasurement
{
public:
	FrameMeasurement();
	~FrameMeasurement();


	//--------------------------/
	//����
	//--------------------------/
	virtual void	MeasureTime();			//���Ԃ��v��
	virtual int		GetNowTime();			//���݂̎��Ԃ��擾
	virtual bool	CheckSpecifiedTime(int time);	//�w�莞�Ԃ𒲂ׂ�
	virtual bool	CheckTimeElaped(int time);		//���Ԃ��o�߂��������ׂ�
	virtual bool	CheckTimeReach(int time);		//�w�肵�����ԂɒB������
	virtual void	SetTime(int time);				//���Ԃ��Z�b�g
	
private:
	int		count;		//�ӂ�[�ގ���
};

