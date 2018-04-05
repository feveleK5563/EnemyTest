#include "TimeCnt.h"

//------------------------------
//�R���X�g���N�^
//------------------------------
FrameMeasurement::FrameMeasurement() : count(0)
{

}

//------------------------------
//�f�X�g���N�^
//------------------------------
FrameMeasurement::~FrameMeasurement()
{

}


//---------------------------------------------------------
//�t���[�����Ԃ��v������
//---------------------------------------------------------
void	FrameMeasurement::MeasureTime()
{
	count++;
}

//---------------------------------------------------------
//���݂̃t���[�����Ԃ�Ԃ�
//---------------------------------------------------------
int		FrameMeasurement::GetNowTime()
{
	return count;
}

//---------------------------------------------------------
//�w��t���[�����Ԃ��𒲂ׂ�
//---------------------------------------------------------
bool	FrameMeasurement::CheckSpecifiedTime(int time)
{
	if (count == time) { return true; }
	return false;
}

//--------------------------------------------------------
//���Ԃ��o�߂������𒲂ׂ�
//--------------------------------------------------------
bool	FrameMeasurement::CheckTimeElaped(int time)
{
	if (count > time) { return true; }
	return false;
}

bool	FrameMeasurement::CheckTimeReach(int time)
{
	if (count <= time) { return true; }
	return false;
}

//---------------------------------------------------------
//�t���[�����Ԃ��Z�b�g����
//---------------------------------------------------------
void	FrameMeasurement::SetTime(int time)
{
	count = time;
}