#include "EnemyMoveTransition.h"

//-----------------------------------------------
//���Ԑ����̐ݒ�
void EnemyMoveTransition::SetTime(int mt)
{
	maxTime = mt;
}

//-----------------------------------------------
//�J�ڂȂ�
bool ETransition_Non::Transition()
{
	return false;
}

//-----------------------------------------------
//���Ԍo��
bool ETransition_Timer::Transition()
{
	++timeCnt;
	if (timeCnt >= maxTime)
	{
		timeCnt = 0;
		return true;
	}

	return false;
}